/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** animations_destroy
*/

#include <SFML/Graphics/RectangleShape.h>
#include <stdlib.h>

#include "Rpg/Entities/animations.h"

void animations_destroy(animations_t *anim, int destroy_lengths,
    int destroy_rect, int destroy_frames)
{
    if (destroy_frames) {
        for (int i = 0; i < anim->anim_count; i++)
            free(anim->anim_frames[i]);
        free(anim->anim_frames);
    }
    if (destroy_lengths)
        free(anim->anim_lengths);
    if (destroy_rect && anim->rect)
        sfRectangleShape_destroy(*anim->rect);
}
