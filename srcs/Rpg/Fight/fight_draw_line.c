/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight_draw_line
*/

#include "Rpg/Fight/fight.h"
#include "My/my_display.h"

static int get_line_init(int *p0, int *p1, int *deltabs, int *add_other_elmt)
{
    int deltas[2] = {p1[0] - p0[0], p1[1] - p0[1]};
    int delta_abs[2] = {abs(deltas[0]), abs(deltas[1])};
    int id = (delta_abs[1] > delta_abs[0]);
    int end;

    *add_other_elmt = (deltas[id] < 0 && deltas[!id] < 0) || \
    (deltas[id] > 0 && deltas[!id] > 0);
    deltabs[0] = delta_abs[0];
    deltabs[1] = delta_abs[1];
    end = (deltas[id] < 0) ? p0[id] : p1[id];
    if (deltas[id] < 0) {
        p0[0] = p1[0];
        p0[1] = p1[1];
    }
    return end;
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

int *fight_get_line(fight_t *fight, int from, int to)
{
    int ps[4];
    int deltabs[2];
    int add_other = init_points(fight, from, to, ps);
    int end = get_line_init(ps, ps + 2, deltabs, &add_other);
    int id = (deltabs[1] > deltabs[0]);
    int err = 2 * deltabs[!id] - deltabs[id];
    int *line;
    int i = 0;

    if (from == -1 || to == -1)
        return NULL;
    line = malloc(sizeof(int) * (3 + end - ps[id]));
    line[i++] = fight_vec_to_pos(fight, (sfVector2i){ps[0], ps[1]});
    while (ps[id]++ < end) {
        err += 2 * ((err < 0) ? deltabs[!id] : (deltabs[!id] - deltabs[id]));
        if (err >= 0)
            ps[!id] += (add_other) ? 1 : -1;
        line[i++] = fight_vec_to_pos(fight, (sfVector2i){ps[0], ps[1]});
    }
    line[i] = END_ARRAY;
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