/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Entity animations
*/

#ifndef ANIMATIONS_H_
#define ANIMATIONS_H_

#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>

typedef struct animations animations_t;
typedef void (*on_animation_end)(animations_t *);

struct animations {
    int paused;
    int anim_count;
    int current_anim;
    int current_frame;
    float current_frame_duration;
    float frame_duration;
    int *anim_lengths;
    void *user_data;
    sfRectangleShape **rect;
    sfIntRect **anim_frames;
    on_animation_end end_callback;
};

void animations_init(animations_t *anim, int anim_count, int *anims_lengths,
    sfIntRect **anim_frames);
void animations_update_rect(animations_t *anim);
void animations_update(animations_t *anim, float dt);
void animations_reset(animations_t *anim);
void animations_pause(animations_t *anim);
void animations_set_animation(animations_t *anim, int anim_id);
void animations_destroy(animations_t *anim, int destroy_lengths,
    int destroy_rect, int destroy_frames);

#endif /* !ANIMATIONS_H_ */
