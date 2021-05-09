/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Updates a spell infobox
*/

#include "functions.h"
#include "Rpg/InfoBox/infobox_spell.h"

static void update_type(infobox_spell_base_t *info, spell_base_t *spell)
{
    char *str = NULL;
    sfVector3f pos = (sfVector3f){
        0.35 * info->base.box_size.x, 0.15 * info->base.box_size.y, -1};

    switch (spell->type) {
        case SPELL_ATTACK: str = "Attack"; break;
        case SPELL_HEAL: str = "Heal"; break;
        case SPELL_EFFECT: str = "Effect"; break;
        case SPELL_DEBUFF: str = "Debuff"; break;
        default: break;
    }
    infobox_init_text(info->type, "Type: %s", pos, str);
}

static void infobox_spell_set_spell_2(
    infobox_spell_base_t *info, spell_base_t *spell)
{
    sfVector2f bs = info->base.box_size;

    info->spell = spell;
    infobox_init_text(
        info->name, spell->name, (sfVector3f){0.65 * bs.x, 0.07 * bs.y, 0});
    update_type(info, spell);
    infobox_init_text(info->ap, "AP: %d",
        (sfVector3f){0.1 * bs.x, 0.25 * bs.y, -1}, spell->ap);
    infobox_init_text(info->po, "PO: %d",
        (sfVector3f){0.55 * bs.x, 0.25 * bs.y, -1}, spell->po);
    infobox_init_text(info->area, "Area: %d",
        (sfVector3f){0.1 * bs.x, 0.35 * bs.y, -1}, spell->area);
    infobox_init_text(info->turn_limit, "Casts: %d/%d",
        (sfVector3f){0.55 * bs.x, 0.35 * bs.y, -1}, MAX(0, spell->cast_left),
        spell->turn_limit);
}

static void update_substruct(infobox_spell_base_t *info, spell_base_t *spell)
{
    switch (info->spell->type) {
        case SPELL_ATTACK:
            infobox_spell_attack_set_spell(
                (infobox_spell_attack_t *)info, (spell_attack_t *)spell);
            break;
        case SPELL_HEAL:
            infobox_spell_heal_set_spell(
                (infobox_spell_heal_t *)info, (spell_heal_t *)spell);
            break;
        case SPELL_DEBUFF:
            infobox_spell_debuff_set_spell(
                (infobox_spell_debuff_t *)info, (spell_debuff_t *)spell);
            break;
        case SPELL_EFFECT:
            infobox_spell_effect_set_spell(
                (infobox_spell_effect_t *)info, (spell_effect_t *)spell);
            break;
        default: break;
    }
}

void infobox_spell_set_spell(
    infobox_spell_base_t **info_ptr, spell_base_t *spell)
{
    if (!spell)
        return;
    if (spell->type != (*info_ptr)->spell->type) {
        infobox_base_t *new_base = infobox_recreate(
            INFOBOX_SPELL, spell, (infobox_base_t *)(*info_ptr));

        infobox_destroy((infobox_base_t *)(*info_ptr));
        *info_ptr = (infobox_spell_base_t *)new_base;
        return;
    }
    infobox_reset_box_size(&(*info_ptr)->base);
    infobox_spell_set_spell_2(*info_ptr, spell);
    sfRectangleShape_setTextureRect((*info_ptr)->base.icon,
        (sfIntRect){64 * (*info_ptr)->spell->texture_id, 0, 64, 64});
    update_substruct(*info_ptr, spell);
}
