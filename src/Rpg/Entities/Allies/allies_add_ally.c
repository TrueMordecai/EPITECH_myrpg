/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** allies_add_ally
*/

#include "Rpg/Entities/allies.h"
#include "Rpg/rpg.h"
#include "functions.h"

void allies_add_ally(allies_t *allies, entity_t *ally)
{
    my_vec_push(&allies->allies, &ally);
    if (allies->allies.length > MAX_ALLIES_IN_FIGHT)
        return;
    for (int i = 0; i < MAX_ALLIES_IN_FIGHT; i++) {
        if (allies->selected_allies[i] == -1) {
            allies->selected_allies[i] = i;
            break;
        }
    }
}

void allies_add_random_ally(allies_t *allies)
{
    entity_t *entity = entity_create(NULL, ALLY, ALLIES, 0);

    entity->stats = stats_create();
    entity->rect = sfRectangleShape_create();
    entity->name = "Green Man";
    sfRectangleShape_setSize(entity->rect, (sfVector2f){32, 32});
    sfRectangleShape_setTexture(entity->rect,
        get_texture(&allies->rpg->state->game_data->assets, entity->name),
        true);
    for (int i = 0; i < 4; i++) {
        entity->stats->level = get_randi(1, 5);
        entity->stats->elements[i] = get_randi(0, 20);
        entity->stats->resistances[i] = get_randi(0, 20);
    }
    entity_init_spells(entity, allies->rpg);
    allies_add_ally(allies, entity);
}