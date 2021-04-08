/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight_test_sight
*/

#include "Rpg/Fight/fight.h"
#include "My/my_memory.h"

static int is_line_valid(fight_t *fight, int *line, int start)
{
    if (!line)
        return 0;
    for (int k = 0; line[k] != END_ARRAY; k++)
        if (line[k] != start && (((cell_is_occupied(&fight->grid[line[k]]) && \
            line[k + 1] != END_ARRAY)) || fight->grid[line[k]].physic == SOLID))
            return 0;
    return 1;
}

static void test_lines(fight_t *fight, int start, int *cells, int *outs)
{
    int *line;
    int valid;

    for (int i = 0; cells[i] != END_ARRAY; i++) {
        if (cells[i] == INEXISTING)
            continue;
        line = fight_get_line(fight, start, cells[i]);
        valid = is_line_valid(fight, line, start);
        if (!valid)
            outs[i] = 1;
        if (valid)
            valid = 0;
        free(line);
    }
}

int *fight_get_sight(fight_t *fight, sfVector2i from_range, \
int need_free_cell, int **spell_range)
{
    int *outs = my_calloc(sizeof(int) * (1 + from_range.y * \
    (from_range.y + 1) * 2), 0);

    if (!(*spell_range))
        *spell_range = fight_get_range(fight, from_range.x, \
        from_range.y, WALKABLE);
    for (int i = 0; (*spell_range)[i] != END_ARRAY; i++) {
        if ((*spell_range)[i] == -1 || (*spell_range)[i] == from_range.x)
            continue;
        if (need_free_cell && cell_is_occupied(&fight->grid[(*spell_range)[i]]))
            outs[i] = 1;
    }
    test_lines(fight, from_range.x, (*spell_range), outs);
    return outs;
}

void fight_show_sight(fight_t *fight, int from, int range, int need_free_cell)
{
    int *cells = NULL;
    int *outs = fight_get_sight(fight, \
    (sfVector2i){from, range}, need_free_cell, &cells);

    for (int i = 0; cells[i] != END_ARRAY; i++)
        fight_place_rect(fight, cells[i], (outs[i]) ? \
    sfColor_fromRGBA(89, 87, 212, 100) : sfColor_fromRGBA(17, 14, 196, 100), 0);
    free(cells);
    free(outs);
}