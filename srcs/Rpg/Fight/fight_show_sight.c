/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight_test_sight
*/

#include "Rpg/Fight/fight.h"
#include "My/my_memory.h"

static int is_line_valid(fight_t *fight, int *line)
{
    if (!line)
        return 0;
    for (int k = 0; line[k] != END_ARRAY; k++)
        if (((cell_is_occupied(&fight->grid[line[k]]) && \
            line[k + 1] != END_ARRAY)) || fight->grid[line[k]].physic == SOLID)
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
        valid = is_line_valid(fight, line);
        if (!valid)
            outs[i] = 1;
        free(line);
    }
}

void fight_show_sight(fight_t *fight, int from, int range, int need_free_cell)
{
    int *cells = fight_get_range(fight, from, range, WALKABLE);
    int *outs = my_calloc(sizeof(int) * (1 + range * (range + 1) * 2), 0);

    for (int i = 0; cells[i] != END_ARRAY; i++) {
        if (cells[i] == -1)
            continue;
        if (need_free_cell && cell_is_occupied(&fight->grid[cells[i]]))
            outs[i] = 1;
    }
    test_lines(fight, from, cells, outs);
    for (int i = 0; cells[i] != END_ARRAY; i++)
        fight_place_rect(fight, cells[i], (outs[i]) ? \
    sfColor_fromRGBA(89, 87, 212, 100) : sfColor_fromRGBA(17, 14, 196, 100), 0);
    free(cells);
    free(outs);
}