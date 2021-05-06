/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** zone interract
*/

#include "Rpg/rpg.h"

int zone_interract_npc(zone_t *zone, sfVector2i pos, int special)
{
    quest_t *current_quest;
    if (special != NPC)
        return 0;
    current_quest = quests_get_current(&zone->map->rpg->quests);
    if (current_quest->quest_type == QUEST_TALK
        && current_quest->talk_to_pnj.pnj_id == zone->id)
        quests_validate(&zone->map->rpg->quests);
    return 1;
}
