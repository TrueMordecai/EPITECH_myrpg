/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** ai_get_path
*/

#include "Rpg/Fight/fight.h"

void free_tmp_path(my_vec_t *path)
{
    my_vec_free(path, NULL);
    free(path);
}

my_vec_t *get_nearest_side_path(
    fight_t *fight, int from, int to, size_t *min_len)
{
    sfVector2i vec_to = fight_pos_to_vec(fight, to, 0);
    sfVector2i test_pos;
    my_vec_t *tmp;
    my_vec_t *path = NULL;

    for (int i = 0; i < 4; i++) {
        test_pos = vec_to;
        if (i % 2 == 0)
            test_pos.x += ((i) ? 1 : -1);
        else
            test_pos.y += ((i == 3) ? 1 : -1);
        tmp = fight_get_path(fight, from, fight_vec_to_pos(fight, test_pos));
        if (tmp && tmp->length < *min_len) {
            *min_len = tmp->length;
            free_tmp_path(path);
            path = tmp;
        } else
            free_tmp_path(tmp);
    }
    return path;
}
