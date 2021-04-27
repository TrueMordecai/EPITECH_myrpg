/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** animations_set_animation
*/

#include "Rpg/Entities/animations.h"

void animations_reset(animations_t *anim)
{
    anim->current_frame = 0;
    anim->current_frame_duration = 0;
    animations_update_rect(anim);
}

void animations_pause(animations_t *anim)
{
    anim->current_frame = 0;
    anim->current_frame_duration = 0;
    animations_update_rect(anim);
    anim->paused = 1;
}

void animations_set_animation(animations_t *anim, int anim_id)
{
    anim->current_anim = anim_id;
    anim->paused = 0;
    animations_reset(anim);
}