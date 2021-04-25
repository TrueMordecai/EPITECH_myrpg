/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** infobox_base_create
*/

#include "Rpg/InfoBox/infobox.h"
#include "Rpg/rpg.h"
#include "Rpg/InfoBox/infobox_effect.h"
#include "Rpg/InfoBox/infobox_entity.h"
#include "Rpg/InfoBox/infobox_spell.h"

static infobox_base_t *infobox_alloc(enum infobox_type type, void *data)
{
    switch (type) {
        case INFOBOX_SPELL:
            if (!data)
                return NULL;
            switch (((spell_base_t *)data)->type) {
                case SPELL_ATTACK:
                    return malloc(sizeof(infobox_spell_attack_t));
                case SPELL_HEAL: return malloc(sizeof(infobox_spell_heal_t));
                case SPELL_EFFECT:
                    return malloc(sizeof(infobox_spell_effect_t));
                case SPELL_DEBUFF:
                    return malloc(sizeof(infobox_spell_debuff_t));
                default: return NULL;
            }
        case INFOBOX_EFFECT: return malloc(sizeof(infobox_effect_t));
        case INFOBOX_ENTITY: return malloc(sizeof(infobox_entity_t));
        default: return NULL; ;
    }
}

infobox_base_t *infobox_create(
    rpg_t *rpg, enum infobox_type type, void *data, char *font_name)
{
    infobox_base_t *base = infobox_alloc(type, data);

    base->rpg = rpg;
    base->type = type;
    base->font = get_font(&rpg->state->game_data->assets, font_name);
    infobox_init(base, data, font_name);
    return base;
}