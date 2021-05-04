/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity_attack
*/

#include <unistd.h>

#include "Rpg/Fight/fight.h"
#include "Rpg/rpg.h"

static void update_anim(entity_t *entity, action_t *action)
{
    sfVector2i pos_from = fight_pos_to_vec(entity->fight, entity->pos, 0);
    sfVector2i pos_aim =
        fight_pos_to_vec(entity->fight, action->attack.cell, 0);
    sfVector2i delta = {pos_aim.x - pos_from.x, pos_aim.y - pos_from.y};
    int dir = 0;
    sfIntRect rect;

    if (delta.x && abs(delta.x) >= abs(delta.y))
        dir = 2 + (delta.x > 0);
    else
        dir = (delta.y < 0);
    rect = (sfIntRect){16 * dir, 64, 16, 16};
    sfRectangleShape_setTextureRect(entity->rect, rect);
}

void entity_attack(entity_t *entity, action_t *act)
{
    audio_manager_t *audio = &entity->fight->rpg->state->game_data->audio;

    update_anim(entity, act);
    switch (act->attack.spell->type) {
        case SPELL_ATTACK: play_sound(audio, "spell_attack"); break;
        case SPELL_HEAL: play_sound(audio, "spell_heal"); break;
        case SPELL_EFFECT: play_sound(audio, "spell_effect"); break;
        case SPELL_DEBUFF: play_sound(audio, "spell_debuff"); break;
        default: break;
    }
}
