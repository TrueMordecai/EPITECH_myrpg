/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity_create
*/

#include <stdlib.h>
#include <libmy/printf.h>

#include "Rpg/Fight/fight.h"
#include "Rpg/Entities/entity.h"

void entity_init_rect(entity_t *entity, sfColor color)
{
    sfVector2i loc_pos = fight_pos_to_vec(entity->fight, entity->pos, 0);
    sfVector2f pos = fight_pos_to_world_vec(entity->fight, entity->pos);

    my_printf("Pos ennemy (%d, %d)\n", loc_pos.x, loc_pos.y);
    pos.y -= 32;
    entity->rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(entity->rect, color);
    sfRectangleShape_setPosition(entity->rect, pos);
    sfRectangleShape_setSize(entity->rect, (sfVector2f){32, 64});
    sfRectangleShape_setOutlineColor(entity->rect, sfBlack);
    sfRectangleShape_setOutlineThickness(entity->rect, -0.5);
}

entity_t *entity_create(void *datas, enum entity_type_e type, \
enum team_e team, int pos)
{
    entity_t *entity = malloc(sizeof(entity_t));

    entity->datas = datas;
    entity->type = type;
    entity->team = team;
    entity->pos = pos;
    entity->stats = NULL;
    entity->move_possibilities = NULL;
    entity->move_path = NULL;
    entity->spell_sight = NULL;
    entity->spell_range = NULL;
    entity->spell_select = -1;
    entity->state = IDLE;
    entity->rect = NULL;
    return entity;
}