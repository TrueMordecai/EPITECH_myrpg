/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** infobox_spell_update
*/

#include <libmy/printf.h>
#include <stdlib.h>

#include "Rpg/InfoBox/infobox_entity.h"
#include "Rpg/InfoBox/infobox_spell.h"

static void resize_text_array(
    infobox_spell_attack_t *info, spell_attack_t *spell)
{
    int nb_lines = 0;
    int line = 0;

    for (int i = 0; i < 4; i++)
        nb_lines += (spell->damages[i] != 0);
    if (info->nb_lines == nb_lines)
        return;
    if (info->nb_lines)
        infobox_spell_attack_destroy_lines(info);
    info->nb_lines = nb_lines;
    info->elements[0] = malloc(sizeof(sfText *) * nb_lines);
    info->elements[1] = malloc(sizeof(sfText *) * nb_lines);
    for (int i = 0; i < 4; i++) {
        if (!spell->damages[i])
            continue;
        infobox_create_text(
            &info->base.base, &info->elements[0][line], sfWhite, 25);
        infobox_create_text(
            &info->base.base, &info->elements[1][line++], sfWhite, 25);
    }
}

void infobox_spell_attack_set_spell_2(
    infobox_spell_attack_t *info, spell_attack_t *spell)
{
    int line = 0;
    sfVector2f bs = info->base.base.box_size;

    infobox_init_text(
        info->damages, "Damages:", (sfVector3f){0.05 * bs.x, 0.44 * bs.y, -1});
    for (int i = 0; i < 4; i++) {
        if (spell->damages[i] == 0)
            continue;
        infobox_init_text(info->elements[0][line], ELEMENTS_NAMES[i],
            (sfVector3f){0.1 * bs.x, (0.5 + line * 0.06) * bs.y, -1});
        infobox_init_text(info->elements[1][line], "%d",
            (sfVector3f){0.4 * bs.x, (0.5 + line * 0.06) * bs.y, 0},
            spell->damages[i]);
        line += 1;
    }
    infobox_set_box_size((infobox_base_t *)&info->base,
        (sfVector2f){bs.x, bs.y * (0.5 + line * 0.06)}, 1);
}

void infobox_spell_attack_set_spell(
    infobox_spell_attack_t *info, spell_attack_t *spell)
{
    if (!spell)
        return;
    resize_text_array(info, spell);
    infobox_reset_box_size(&info->base.base);
    infobox_spell_attack_set_spell_2(info, spell);
}
