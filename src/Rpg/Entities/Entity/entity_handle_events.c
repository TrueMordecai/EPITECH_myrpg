/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity_handle_events
*/

#include "Rpg/Fight/fight.h"
#include "Rpg/rpg.h"

static void move(entity_t *entity)
{
    if (entity->move_path)
        play_sound(&entity->fight->rpg->state->game_data->audio, "move");
    entity_move(entity, 0);
}

void entity_handle_events(entity_t *entity, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (entity->spell_select == -1)
            move(entity);
        else
            entity_cast_spell(entity, entity->spell_cell);
    }
}