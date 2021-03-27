/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** player
*/

#ifndef RPG_PLAYER_H
#define RPG_PLAYER_H

#include <SFML/Graphics.h>
#include "Physics/physics.h"

typedef struct player_t {
    sfRectangleShape *rect;
    sfVector2f pos;
    pe_body_t *body;
} player_t;

player_t *player_create(void);
pe_body_t *player_init_physic(player_t *player, pe_world_t *world);
void player_handle_input(player_t *player, sfEvent event);
void player_update(player_t *player, float dt);
void player_draw(player_t *player, sfRenderWindow *wind);
void player_destroy(player_t *player);

#endif /* !RPG_PLAYER_H */