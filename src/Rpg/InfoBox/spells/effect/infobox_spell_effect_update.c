/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** infobox_spell_update
*/

#include <libmy/printf.h>
#include <stdarg.h>
#include <stdlib.h>

#include "functions.h"
#include "Rpg/InfoBox/infobox_entity.h"
#include "Rpg/InfoBox/infobox_spell.h"

void add_text(infobox_spell_effect_t *info, char *format, int boost, ...)
{
    spell_effect_t *spell = (spell_effect_t *)info->base.spell;
    my_vec_t *vec = (boost) ? &info->boosts : &info->damages;
    sfText *text = NULL;
    sfVector3f pos = {(!boost && (spell->type & EFFECT_BOOST)) ? 0.62 : 0.05,
        0.55 + (0.05 * vec->length), -1};
    char *str = NULL;
    va_list args;

    pos.x *= info->base.base.box_size.x;
    pos.y *= info->base.base.box_size.y;
    infobox_create_text(&info->base.base, &text, sfWhite, 25);
    va_start(args, boost);
    my_vasprintf(&str, format, args);
    va_end(args);
    sfText_setString(text, str);
    infobox_set_text_pos(text, pos);
    my_vec_push(vec, &text);
    free(str);
}

static void update_vecs(infobox_spell_effect_t *info, spell_effect_t *spell)
{
    for (int i = 0; i < 4 && (spell->type & EFFECT_DAMAGE); i++) {
        if (spell->damages[i])
            add_text(info, "%d %s", 0, spell->damages[i], ELEMENTS_NAMES[i]);
    }
    if (!(spell->type & EFFECT_BOOST))
        return;
    if (spell->buff.life)
        add_text(info, "%d HP", 1, spell->buff.life);
    if (spell->buff.ap)
        add_text(info, "%d AP", 1, spell->buff.ap);
    if (spell->buff.mp)
        add_text(info, "%d MP", 1, spell->buff.mp);
    for (int i = 0; i < 4; i++) {
        if (spell->buff.elements[i])
            add_text(
                info, "%d %s", 1, spell->buff.elements[i], ELEMENTS_NAMES[i]);
        if (spell->buff.resistances[i])
            add_text(info, "%d%% %s resistance", 1, spell->buff.resistances[i],
                ELEMENTS_NAMES[i]);
    }
}

void infobox_spell_effect_set_spell(
    infobox_spell_effect_t *info, spell_effect_t *spell)
{
    sfVector2f bs;

    if (!spell)
        return;
    infobox_reset_box_size(&info->base.base);
    bs = info->base.base.box_size;
    infobox_spell_effect_clear_vecs(info);
    update_vecs(info, spell);
    infobox_init_text(info->lifetime, "Duration: %d",
        (sfVector3f){0.1 * bs.x, 0.45 * bs.y, -1}, spell->lifetime);
    infobox_init_text(info->max_cumul, "Max stack: %d",
        (sfVector3f){0.55 * bs.x, 0.45 * bs.y, -1}, spell->max_cumul);
    infobox_init_text(
        info->boost, "Boosts:", (sfVector3f){0.02 * bs.x, 0.5 * bs.y, -1});
    infobox_init_text(info->damage, "Damages:",
        (sfVector3f){
            ((info->boosts.length) ? 0.59 : 0.02) * bs.x, 0.5 * bs.y, -1});
    infobox_set_box_size((infobox_base_t *)&info->base,
        (sfVector2f){bs.x, bs.y * (0.55 + 0.05 * 
            MAX(info->boosts.length, info->damages.length))}, 1);
}
