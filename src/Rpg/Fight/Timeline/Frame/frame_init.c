/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** frame_init
*/

#include "Rpg/Fight/timeline.h"

static void init_entity_rect(frame_t *frame, entity_t *entity, int id)
{
    int blue = (entity->team == ALLIES);

    sfRectangleShape_setPosition(frame->entity_rect,
        (sfVector2f){id * (FRAME_WIDTH + FRAME_SPACING), 0});
    sfRectangleShape_setSize(
        frame->entity_rect, (sfVector2f){FRAME_WIDTH, FRAME_WIDTH});
    sfRectangleShape_setFillColor(
        frame->entity_rect, sfRectangleShape_getFillColor(entity->rect));
    sfRectangleShape_setOutlineColor(frame->entity_rect, sfBlack);
    sfRectangleShape_setOutlineThickness(frame->entity_rect, -1);
    sfRectangleShape_setTexture(
        frame->entity_rect, sfRectangleShape_getTexture(entity->rect), 0);
    sfRectangleShape_setTextureRect(
        frame->entity_rect, (sfIntRect){0, 0, 16, 16});
    sfRectangleShape_setPosition(
        frame->bg, (sfVector2f){id * (FRAME_WIDTH + FRAME_SPACING), 0});
    sfRectangleShape_setSize(
        frame->bg, (sfVector2f){FRAME_WIDTH, FRAME_WIDTH});
    sfRectangleShape_setFillColor(
        frame->bg, sfColor_fromRGBA((!blue) * 255, 0, blue * 255, 125));
}

void frame_init(frame_t *frame, entity_t *entity, int id)
{
    if (!frame)
        return;
    frame->entity = entity;
    frame->entity_rect = sfRectangleShape_create();
    frame->bg = sfRectangleShape_create();
    init_entity_rect(frame, entity, id);
    frame->life_bar = sfRectangleShape_create();
    sfRectangleShape_setPosition(frame->life_bar,
        (sfVector2f){id * (FRAME_WIDTH + FRAME_SPACING), FRAME_WIDTH});
    sfRectangleShape_setSize(frame->life_bar, (sfVector2f){0, 5});
    sfRectangleShape_setFillColor(frame->life_bar, sfRed);
    sfRectangleShape_setOutlineColor(frame->life_bar, sfBlack);
    sfRectangleShape_setOutlineThickness(frame->life_bar, -1);
}