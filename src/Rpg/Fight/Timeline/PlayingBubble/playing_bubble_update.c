/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** playing_bubble_update
*/

#include <libmy/io/iostream.h>
#include <libmy/printf.h>

#include "Rpg/Fight/timeline.h"

void playing_bubble_update(playing_bubble_t *bubble, entity_t *entity)
{
    char buff[9];
    stats_t *stats;
    float life_ratio;
    entity_t *testing =
        ((entity->team == ENNEMIES) ? bubble->last_entity : entity);

    if (!testing)
        return;
    stats = testing->stats;
    life_ratio = stats->current_life / (float)stats->life;
    bubble->last_entity = testing;
    my_snprintf(
        buff, 9, "%d/%d PA", testing->stats->current_pa, testing->stats->pa);
    sfText_setString(bubble->text_pa, buff);
    my_snprintf(
        buff, 9, "%d/%d PM", testing->stats->current_pm, testing->stats->pm);
    sfText_setString(bubble->text_pm, buff);
    sfCircleShape_setFillColor(
        bubble->circle, sfColor_fromRGB(255 * life_ratio, 0, 0));
}