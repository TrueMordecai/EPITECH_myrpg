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
#include "Rpg/Entities/entity.h"

struct rpg_t;

typedef struct player_t {
    sfVector2f pos;
    sfVector2i last_pos;
    sfVector2i dir;
    pe_body_t *body;
    entity_t *entity;
    struct rpg_t *rpg;
} player_t;

player_t *player_create(struct rpg_t *rpg);
pe_body_t *player_init_physic(player_t *player, pe_world_t *world);
void player_update(player_t *player, float dt);
void player_remove_equipment_stats(player_t *player);
void player_set_equipment_stats(player_t *player);
void player_draw(player_t *player, sfRenderWindow *wind);
void player_destroy(player_t *player);

#endif /* !RPG_PLAYER_H */
