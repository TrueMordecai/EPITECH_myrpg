/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** fight_test_sight
*/

#include <libmy/memory.h>
#include "Rpg/Fight/fight.h"

static int is_line_valid(fight_t *fight, int *line, int start)
{
    if (!line)
        return 0;
    for (int k = 0; line[k] != END_ARRAY; k++)
        if (line[k] != start
            && (((cell_is_occupied(&fight->grid[line[k]])
                    && line[k + 1] != END_ARRAY))
                || fight->grid[line[k]].physic == SOLID))
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

int *fight_get_sight(fight_t *fight, sfVector2i from_range,
    sfVector2i max_range_need_free, int **spell_range)
{
    size_t size = sizeof(int) * (2 + (from_range.y * (from_range.y + 1)) * 2);
    int *outs = my_memset(malloc(size), -1, size);

    outs[(1 + (from_range.y * (from_range.y + 1)) * 2)] = END_ARRAY;
    if (max_range_need_free.x == -1)
        max_range_need_free.x = from_range.y;
    if (!(*spell_range))
        *spell_range = fight_get_range(fight, from_range.x, from_range.y, 1);
    for (int i = 0; (*spell_range)[i] != END_ARRAY; i++) {
        if ((*spell_range)[i] == -1)
            continue;
        if ((*spell_range)[i] == from_range.x
            || get_heuristic_cost(fight, from_range.x, (*spell_range)[i])
                <= max_range_need_free.x)
            outs[i] = 0;
        if (max_range_need_free.y
            && cell_is_occupied(&fight->grid[(*spell_range)[i]]))
            outs[i] = 1;
    }
    test_lines(fight, from_range.x, (*spell_range), outs);
    return outs;
}

void fight_show_sight(fight_t *fight, int from, int range, int need_free_cell)
{
    int *cells = NULL;
    int *outs = fight_get_sight(fight, (sfVector2i){from, range},
        (sfVector2i){range, need_free_cell}, &cells);

    for (int i = 0; cells[i] != END_ARRAY; i++)
        fight_place_rect(fight, cells[i],
            (outs[i]) ? sfColor_fromRGBA(89, 87, 212, 100)
                      : sfColor_fromRGBA(17, 14, 196, 100),
            0);
    free(cells);
    free(outs);
}
