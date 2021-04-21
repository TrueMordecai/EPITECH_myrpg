/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** animation_update
*/
#include <stdio.h>

#include "Rpg/Entities/animations.h"

void animations_update_rect(animations_t *anim)
{
    sfRectangleShape_setTextureRect(*anim->rect,
        anim->anim_frames[anim->current_anim][anim->current_frame]);
}

void animations_update(animations_t *anim, float dt)
{
    int start_anim = anim->current_anim;
    int start_frame = anim->current_frame;

    if (anim->paused)
        return;
    anim->current_frame_duration += dt;
    if (anim->current_frame_duration >= anim->frame_duration) {
        anim->current_frame_duration = 0;
        anim->current_frame++;
    }
    if (anim->current_frame >= anim->anim_lengths[anim->current_anim]) {
        anim->current_frame = 0;
        if (anim->end_callback != NULL)
            (*anim->end_callback)(anim);
    }
    if (start_anim != anim->current_anim || start_frame != anim->current_frame)
        animations_update_rect(anim);
}