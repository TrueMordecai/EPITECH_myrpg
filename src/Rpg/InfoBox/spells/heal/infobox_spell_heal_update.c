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

void infobox_spell_heal_set_spell(
    infobox_spell_heal_t *info, spell_heal_t *spell)
{
    sfVector2f bs;

    if (!spell)
        return;
    infobox_reset_box_size(&info->base.base);
    bs = info->base.base.box_size;
    infobox_init_text(info->heal, "Heal: %d",
        (sfVector3f){0.1 * bs.x, 0.45 * bs.y, -1}, spell->heal);
    infobox_set_box_size(
        (infobox_base_t *)&info->base, (sfVector2f){bs.x, bs.y * 0.5}, 1);
}