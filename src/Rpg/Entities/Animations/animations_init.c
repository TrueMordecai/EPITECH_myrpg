/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** animation_init
*/

#include "Rpg/Entities/animations.h"

void animations_init(animations_t *anim, int anim_count, int *anims_lengths,
    sfIntRect **anim_frames)
{
    anim->paused = 0;
    anim->anim_count = anim_count;
    anim->current_anim = 0;
    anim->current_frame = 0;
    anim->current_frame_duration = 0;
    anim->frame_duration = 0.25;
    anim->anim_lengths = anims_lengths;
    anim->user_data = NULL;
    anim->anim_frames = anim_frames;
    anim->end_callback = NULL;
    anim->rect = NULL;
}