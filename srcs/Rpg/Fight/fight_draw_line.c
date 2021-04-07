/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight_draw_line
*/

#include "Rpg/Fight/fight.h"
#include "My/my_display.h"

static int get_line_init(int *p0, int *p1, int *deltabs)
{
    int deltas[2] = {p1[0] - p0[0], p1[1] - p0[1]};
    int delta_abs[2] = {abs(deltas[0]), abs(deltas[1])};

    deltabs[0] = delta_abs[0];
    deltabs[1] = delta_abs[1];
    return 0;
}

static int init_points(fight_t *fight, int from, int to, int *ps)
{
    sfVector2i p0_v = fight_pos_to_vec(fight, from, 0);
    sfVector2i p1_v = fight_pos_to_vec(fight, to, 0);

    ps[0] = p0_v.x;
    ps[1] = p0_v.y;
    ps[2] = p1_v.x;
    ps[3] = p1_v.y;
    return 0;
}

int sign(int *ps, int axis)
{
    if (ps[2 + axis] - ps[axis] < 0)
        return -1;
    return 1;
}

float correct(float coeff)
{
    return 0.5f - (coeff == fabsf(coeff)) * 0.01;
}

float get_coeff(int *ps, int *deltabs, int *axis)
{
    float coeff;

    if (deltabs[0] <= deltabs[1]) {
        if (deltabs[1] == 0)
            coeff = 0;
        else
            coeff = (ps[2] - ps[0]) / (float)(ps[3] - ps[1]);
        *axis = 0;
    } else {
        if (deltabs[0] == 0)
            coeff = 0;
        else
            coeff = (ps[3] - ps[1]) / (float)(ps[2] - ps[0]);
        *axis = 1;
    }
    return coeff * sign(ps, !(*axis));
}

int *fight_get_line(fight_t *fight, int from, int to)
{
    int ps[4];
    int deltabs[2];
    float coeff = init_points(fight, from, to, ps);
    int axis = get_line_init(ps, ps + 2, deltabs);
    int p[2];
    int *line;

    if (from == -1 || to == -1)
        return NULL;
    coeff = get_coeff(ps, deltabs, &axis);
    line = malloc(sizeof(int) * (deltabs[!axis] + 2));
    for (int i = 0; i <= deltabs[!axis]; i++) {
        p[0] = ps[0] + \
        ((axis) ? i * (sign(ps, !axis)) : i * coeff) + correct(coeff);
        p[1] = ps[1] + \
        ((!axis) ? i * (sign(ps, !axis)) : i * coeff) + correct(coeff);
        line[i] = fight_vec_to_pos(fight, (sfVector2i){p[0], p[1]});
    }
    line[deltabs[!axis] + 1] = END_ARRAY;
    return line;
}

void fight_draw_line(fight_t *fight, int from, int to)
{
    int *line = fight_get_line(fight, from, to);
    int i = 0;

    if (!line)
        return;
    while (line[i] != END_ARRAY)
        fight_place_rect(fight, line[i++], \
        sfColor_fromRGBA(0, 255, 255, 50), C_EMPTY);
    free(line);
}