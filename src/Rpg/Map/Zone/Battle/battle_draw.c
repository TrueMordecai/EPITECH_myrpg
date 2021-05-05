/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** battle draw
*/

#include "Rpg/Fight/fight.h"
#include "Rpg/rpg.h"

void battle_draw_tactical(
    battle_t *battle, sfRenderWindow *wind, sfVector2i min, sfVector2i max)
{
    sfRenderWindow_setView(wind, battle->zone->map->view);
    layer_draw(battle->layer, wind, min, max);
    fight_draw(battle->fight, wind);
}

void battle_draw(
    battle_t *battle, sfRenderWindow *wind, sfVector2i min, sfVector2i max)
{
    if (battle->tactical)
        battle_draw_tactical(battle, wind, min, max);
    else {
        zone_draw_layers(battle->zone, wind, min, max);
        fight_draw(battle->fight, wind);
    }
}
