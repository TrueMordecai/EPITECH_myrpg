/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight_create
*/

#include <libmy/printf.h>
#include <stdlib.h>

#include "Rpg/Entities/player.h"
#include "Rpg/Fight/fight.h"
#include "Rpg/Map/battle.h"
#include "Rpg/rpg.h"
#include "functions.h"

static int get_pos(fight_t *fight, int player_pos)
{
    my_vec_t *tmp = NULL;
    int i = 0;
    int pos;

    do {
        pos = get_randi(0, fight->size.x * fight->size.y - 1);
        if (!cell_is_empty(&fight->grid[pos]) || pos == player_pos)
            continue;
        tmp = fight_get_path(fight, pos, player_pos);
        i++;
    } while (!tmp && i < 100);
    if (tmp) {
        my_vec_free(tmp, NULL);
        free(tmp);
        return pos;
    }
    return -1;
}

static int init_ennemy(fight_t *fight, int pos, int *id)
{
    if (pos == -1) {
        (*id)--;
        return 1;
    }
    fight->entities[*id + 1] =
        entity_create(NULL, ENNEMY_CAC + get_randi(0, 1), ENNEMIES, pos);
    entity_add_spell(fight->entities[*id + 1], get_spell(fight->rpg, "burn"));
    fight->entities[*id + 1]->stats = stats_create();
    fight->entities[*id + 1]->fight = fight;
    entity_init_rect(fight->entities[*id + 1], "Skeleton",
        sfColor_fromInteger((get_randi(0, 16777215) << 8) + 255));
    animations_update_rect(&fight->entities[*id + 1]->anim);
    return 0;
}

static int init_ally(fight_t *fight, int pos, int *id, entity_t *ally)
{
    if (pos == -1) {
        (*id)--;
        return 1;
    }
    fight->entities[*id + 1] = ally;
    fight->entities[*id + 1]->pos = pos;
    sfRectangleShape_setPosition(
        ally->rect, fight_pos_to_world_vec(fight, pos));
    animations_update_rect(&fight->entities[*id + 1]->anim);
    return 0;
}

static void fill_entities(
    fight_t *fight, int nb_ennemies, int player_pos, allies_t *allies)
{
    int nb_allies = CLAMP(allies->allies.length, 0, MAX_ALLIES_IN_FIGHT);
    int nb_entities = nb_ennemies + nb_allies;
    int id_ally = 0;

    for (int i = 0; i < nb_entities; i++) {
        int pos = get_pos(fight, player_pos);

        if (nb_ennemies > 0 && (i % 2 == 0 || nb_allies == 0)) {
            fight->nb_entities -= init_ennemy(fight, pos, &i);
            nb_ennemies--;
            continue;
        }
        if (nb_allies > 0 && (i % 2 || nb_ennemies == 0)) {
            init_ally(fight, pos, &i,
                MY_VEC_GET_ELEM(entity_t *, &allies->allies,
                    allies->selected_allies[id_ally]));
            id_ally++;
            nb_allies--;
        }
    }
}

void fight_init_entities(fight_t *fight, int nb_ennemies, player_t *player)
{
    allies_t *allies = &fight->rpg->allies;
    int nb_allies = CLAMP(allies->allies.length, 0, MAX_ALLIES_IN_FIGHT);

    player->entity->alive = 1;
    fight->entity_turn = 0;
    fight->nb_entities = MAX(0, nb_ennemies) + 1 + nb_allies;
    fight->entities = malloc(sizeof(entity_t *) * fight->nb_entities);
    fight->entities[0] = player->entity;
    fight->entities[0]->pos = player->body->pos.x - fight->pos.x
        + (player->body->pos.y - fight->pos.y) * fight->size.x;
    my_printf(
        "%d entities, including %d allies\n", fight->nb_entities, nb_allies);
    fill_entities(fight, nb_ennemies, fight->entities[0]->pos, allies);
    for (int i = 0; i < fight->nb_entities; i++) {
        stats_reset(fight->entities[i]->stats, 0);
        fight->entities[i]->fight = fight;
        fight->grid[fight->entities[i]->pos].entity = fight->entities[i];
        entity_init(fight->entities[i]);
        animations_set_animation(&fight->entities[i]->anim, 0);
        animations_pause(&fight->entities[i]->anim);
    }
}