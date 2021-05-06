/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** MyRPG handle input
*/

#include <libmy/printf.h>

#include "Rpg/Fight/fight.h"
#include "Rpg/rpg.h"

static void debug_fight_start(rpg_t *rpg, sfEvent event)
{
    if (!event.key.shift || !event.key.control)
        return;
    if (!rpg->map->current_zone->is_battle) {
        battle_start(&rpg->map->current_zone->battle);
    } else
        battle_end(&rpg->map->current_zone->battle);
}

static void quest_debug(rpg_t *rpg, sfEvent event)
{
    if (!event.key.shift || !event.key.control)
        return;
    if (event.key.code == sfKeyO) {
        quest_t *current = quests_get_current(&rpg->quests);

        if (!current)
            my_printf("No quest left\n");
        else
            my_printf("Current quest : %#s\n", current->context);
    }
    if (event.key.code == sfKeyM)
        quests_validate(&rpg->quests);
}

void rpg_handle_event(rpg_t *rpg, sfEvent event)
{
    inventory_handle_events(&rpg->inventory, &event);
    if (event.type == sfEvtKeyPressed) {
        quest_debug(rpg, event);
        switch (event.key.code) {
            case sfKeyAdd: map_zoom_up_down(rpg->map, 1); break;
            case sfKeySubtract: map_zoom_up_down(rpg->map, 0); break;
            case sfKeyT:
                battle_set_tactical(&rpg->map->current_zone->battle);
                break;
            case sfKeyB: debug_fight_start(rpg, event); break;
            case sfKeyE: zone_interract(rpg->map->current_zone); break;
            default: break;
        }
    }
    player_handle_event(rpg->player, event);
    if (rpg->map->current_zone && rpg->map->current_zone->is_battle)
        fight_handle_events(rpg->map->current_zone->battle.fight, event);
}
