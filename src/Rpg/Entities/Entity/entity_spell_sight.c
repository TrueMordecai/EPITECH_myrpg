/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity_spell_sight
*/

#include <libmy/printf.h>

#include "Rpg/Fight/fight.h"

spell_base_t *entity_get_select_spell(entity_t *entity)
{
    int id = entity->spell_select;

    if (id == -1 || (size_t)id >= entity->spells.length)
        return NULL;
    return MY_VEC_GET_ELEM(spell_base_t *, &entity->spells, id);
}

void entity_update_spell_sight(entity_t *entity)
{
    fight_t *fight = entity->fight;
    spell_base_t *spell = entity_get_select_spell(entity);

    free(entity->spell_sight);
    free(entity->spell_range);
    entity->spell_range = NULL;
    entity->spell_sight = NULL;
    if (!spell)
        return;
    my_printf("Spell %#s\n", spell->name);
    entity->spell_sight =
        fight_get_sight(fight, (sfVector2i){entity->pos, spell->po},
            (sfVector2i){-1, 0}, &entity->spell_range);
}

void entity_draw_spell_sight(entity_t *entity, int update)
{
    fight_t *fight = entity->fight;

    if (update)
        entity_update_spell_sight(entity);
    if (!entity->spell_sight || !entity->spell_range)
        return;
    for (int i = 0; entity->spell_range[i] != END_ARRAY; i++)
        fight_place_rect(fight, entity->spell_range[i],
            (entity->spell_sight[i]) ? sfColor_fromRGBA(89, 87, 212, 100)
                                     : sfColor_fromRGBA(17, 14, 196, 100),
            0);
}

static void draw_spell_range(entity_t *entity, spell_base_t *spell, int tile)
{
    int *area = fight_get_range(entity->fight, tile, spell->area, WALKABLE);
    if (!area)
        return;
    for (int i = 0; area[i] != END_ARRAY; i++)
        fight_place_rect(entity->fight, area[i],
            sfColor_fromRGBA(0, 0, 255, 120), WALKABLE);
    free(area);
}

void entity_draw_spell_cell(entity_t *entity)
{
    int tile = fight_get_mouse_tile(entity->fight);
    int valid = 0;
    spell_base_t *spell =
        MY_VEC_GET_ELEM(spell_base_t *, &entity->spells, entity->spell_select);

    entity->spell_cell = -1;
    if (!entity->spell_sight || !entity->spell_range)
        return;
    for (int i = 0; entity->spell_range[i] != END_ARRAY; i++)
        if (entity->spell_range[i] == tile) {
            valid = (!entity->spell_sight[i]);
            break;
        }
    if (!valid)
        return;
    entity->spell_cell = tile;
    if (spell && spell->area > 1)
        draw_spell_range(entity, spell, tile);
    else
        fight_place_rect(
            entity->fight, tile, sfColor_fromRGBA(0, 0, 255, 120), WALKABLE);
}