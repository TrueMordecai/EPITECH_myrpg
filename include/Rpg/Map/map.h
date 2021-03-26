/*
** EPITECH PROJECT, 2021
** My rpg
** File description:
** map struct
*/

#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.h>
#include "Rpg/Map/zone.h"

struct rpg_t;

typedef struct map_t {
    int nb_zones;
    int current_zone_id;
    int tiles_size;
    float current_zoom;
    float zoom_goal;
    zone_t *current_zone;
    sfView *view;
    sfVector2f view_pos;
    sfVector2f view_size;
    zone_t **zones;
    struct rpg_t *rpg;
} map_t;

map_t *map_create(struct rpg_t *rpg);
void map_update_zoom(map_t *map, float dt);
void map_zoom(map_t *map, float value);
void map_zoom_up_down(map_t *map, int zoom_up);
void map_reset_zoom(map_t *map);
void map_correct_pos(map_t *map, float dt);
void map_move(map_t *map, sfVector2f offset);
void map_update(map_t *map, float dt);
void map_draw(map_t *map);
void map_destroy(map_t *map);

#endif /* !MAP_H */