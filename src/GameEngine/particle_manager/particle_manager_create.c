/*
** EPITECH PROJECT, 2021
** MyRPG - Game Engine
** File description:
** Initializes the particle manager
*/

#include <SFML/Graphics/Sprite.h>
#include <stdlib.h>

#include "GameEngine/asset_manager.h"
#include "GameEngine/particle_manager.h"

particle_manager_t *particle_manager_create(asset_manager_t *asset_manager)
{
    particle_manager_t *manager = malloc(sizeof(*manager));

    if (manager == NULL)
        return NULL;
    *manager = (particle_manager_t){0};
    manager->sprites[0] = sfSprite_create();
    if (manager->sprites[0] == NULL) {
        free(manager);
        return NULL;
    }
    sfSprite_setTexture(
        manager->sprites[0], get_texture(asset_manager, "particles"), sfTrue);
    sfSprite_setTextureRect(manager->sprites[0], (sfIntRect){0, 0, 16, 16});
    sfSprite_setScale(manager->sprites[0], (sfVector2f){1, 1});
    return manager;
}
