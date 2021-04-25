/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity_create
*/

#include <libmy/printf.h>
#include <stdlib.h>

#include "Rpg/Entities/entity.h"
#include "Rpg/Fight/fight.h"
#include "Rpg/rpg.h"
#include "GameEngine/game_head.h"

void entity_init_rect(entity_t *entity, char *name, sfColor color)
{
    sfVector2f pos = fight_pos_to_world_vec(entity->fight, entity->pos);

    entity->name = name;
    entity->rect = sfRectangleShape_create();
    sfRectangleShape_setTexture(entity->rect,
        get_texture(&entity->fight->rpg->state->game_data->assets, name), 1);
    sfRectangleShape_setTextureRect(entity->rect, (sfIntRect){0, 0, 16, 16});
    sfRectangleShape_setFillColor(entity->rect, color);
    sfRectangleShape_setPosition(entity->rect, pos);
    sfRectangleShape_setSize(entity->rect, (sfVector2f){32, 32});
}

static void init_animations(entity_t *entity)
{
    int anim_count = 4;
    int *lengths = malloc(sizeof(int) * anim_count);
    sfIntRect **frames = malloc(sizeof(sfIntRect *) * anim_count);

    for (int i = 0; i < anim_count; i++) {
        lengths[i] = 4;
        frames[i] = malloc(sizeof(sfIntRect) * 4);
        for (int j = 0; j < 4; j++)
            frames[i][j] = (sfIntRect){i * 16, j * 16, 16, 16};
    }
    animations_init(&entity->anim, anim_count, lengths, frames);
    entity->anim.rect = &entity->rect;
    entity->anim.paused = 1;
}

entity_t *entity_create(
    void *datas, enum entity_type_e type, enum team_e team, int pos)
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
    entity->fight = NULL;
    entity->alive = 1;
    my_vec_init(&entity->actions, sizeof(action_t));
    my_vec_init(&entity->spells, sizeof(spell_base_t *));
    init_animations(entity);
    return entity;
}