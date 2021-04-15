/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity_compute_move
*/

#include <libmy/printf.h>

#include "Rpg/Fight/fight.h"
#include "functions.h"

int get_allies(fight_t *fight, entity_t *entity, \
my_vec_t *allies);
my_vec_t *get_nearest_side_path(fight_t *fight, int from, \
int to, size_t *min_len);
void move_forward(entity_t *entity, my_vec_t *allies);
void move_to_reachable_sights(entity_t *entity, int *sight, \
my_vec_t *allies);
void flee_away(entity_t *entity, my_vec_t *allies);
int *init_sight(entity_t *entity, my_vec_t *allies, int ally_po);

static void get_reachable_sights(entity_t *entity, my_vec_t *allies)
{
    int po = 5;
    fight_t *fight = entity->fight;
    int *sight = init_sight(entity, allies, 0);
    int sight_pos = 0;

    for (int i = 0; sight[i] != END_ARRAY; i++)
        sight_pos += (sight[i] == 0);
    if (!sight_pos)
        move_forward(entity, allies);
    else
        move_to_reachable_sights(entity, sight, allies);
    free(sight);
}

void entity_compute_move(entity_t *entity)
{
    fight_t *fight = entity->fight;
    my_vec_t allies;

    if (entity->team != ENNEMIES)
        return;
    my_vec_init(&allies, sizeof(entity_t *));
    if (!get_allies(fight, entity, &allies)) {
        my_printf("Allies too far, move forward\n");
        move_forward(entity, &allies);
        return;
    } else
        get_reachable_sights(entity, &allies);
    my_vec_free(&allies, NULL);
}