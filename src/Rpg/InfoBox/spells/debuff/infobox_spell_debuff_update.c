/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** infobox_spell_update
*/

#include <libmy/printf.h>
#include <stdlib.h>

#include "Rpg/InfoBox/infobox_entity.h"
#include "Rpg/InfoBox/infobox_spell.h"

static void update_type(infobox_spell_debuff_t *info, spell_debuff_t *spell)
{
    char *str = "Nothing";
    switch ((int)spell->type) {
        case EFFECT_BOOST: str = "Boosts"; break;
        case EFFECT_DAMAGE: str = "Damages"; break;
        case (EFFECT_DAMAGE | EFFECT_BOOST): str = "Boosts and damages"; break;
        default: break;
    }
    infobox_init_text(info->type, "Debuff: %s",
        (sfVector3f){0.1 * info->base.base.box_size.x,
            0.45 * info->base.base.box_size.y, -1},
        str);
}

void infobox_spell_debuff_set_spell(
    infobox_spell_debuff_t *info, spell_debuff_t *spell)
{
    sfVector2f bs;

    if (!spell)
        return;
    infobox_reset_box_size(&info->base.base);
    bs = info->base.base.box_size;
    update_type(info, spell);
    if (spell->turns)
        infobox_init_text(info->turn_removed, "Remove %d turns.",
            (sfVector3f){0.1 * bs.x, 0.5 * bs.y, -1}, spell->turns);
    else
        infobox_init_text(info->turn_removed, "Remove all turns.",
            (sfVector3f){0.1 * bs.x, 0.5 * bs.y, -1});
    infobox_set_box_size(
        (infobox_base_t *)&info->base, (sfVector2f){bs.x, bs.y * 0.55}, 1);
}