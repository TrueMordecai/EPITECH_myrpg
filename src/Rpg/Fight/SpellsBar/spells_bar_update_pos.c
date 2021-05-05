/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** spells_bar_update_pos
*/

#include "Rpg/Fight/fight.h"
#include "Rpg/Fight/spells_bar.h"

static int update_grabbed(
    spells_bar_t *bar, sfEvent *event, sfRenderWindow *window)
{
    sfVector2i mouse_pos = {event->mouseButton.x, event->mouseButton.y};
    sfVector2f mouse_pos_view =
        sfRenderWindow_mapPixelToCoords(window, mouse_pos, bar->view);

    if (bar->grabbed)
        return 0;
    if (mouse_pos_view.x >= 0
        && mouse_pos_view.x <= FRAME_WIDTH * bar->nb_frames
        && mouse_pos_view.y >= -20 && mouse_pos_view.y <= 0) {
        bar->grabbed = 1;
        bar->last_pos = mouse_pos;
        return 1;
    }
    return 0;
}

static void correct_pos(spells_bar_t *bar, sfRenderWindow *window)
{
    sfVector2u win_size = sfRenderWindow_getSize(window);
    sfVector2i top_left = sfRenderWindow_mapCoordsToPixel(
        window, (sfVector2f){0, -20}, bar->view);
    sfVector2i bottom_right = sfRenderWindow_mapCoordsToPixel(window,
        (sfVector2f){
            SPELLS_BAR_WIDTH * FRAME_WIDTH, FRAME_WIDTH * SPELLS_BAR_HEIGHT},
        bar->view);
    sfVector2f offset = {0, 0};

    if (top_left.x < 0)
        offset.x = top_left.x;
    if (top_left.y < 0)
        offset.y = top_left.y;
    if (offset.x == 0 && bottom_right.x > (int)win_size.x)
        offset.x = bottom_right.x - win_size.x;
    if (offset.y == 0 && bottom_right.y > (int)win_size.y)
        offset.y = bottom_right.y - win_size.y;
    sfView_move(bar->view, offset);
}

static void update_pos(
    spells_bar_t *bar, sfEvent *event, sfRenderWindow *window)
{
    sfVector2i mouse_pos = {event->mouseMove.x, event->mouseMove.y};

    sfView_move(bar->view,
        (sfVector2f){
            bar->last_pos.x - mouse_pos.x, bar->last_pos.y - mouse_pos.y});
    bar->last_pos = mouse_pos;
    correct_pos(bar, window);
}

int spells_bar_handle_move(
    spells_bar_t *bar, sfEvent *event, sfRenderWindow *window)
{
    if (event->type == sfEvtMouseButtonPressed
        && event->mouseButton.button == sfMouseLeft
        && update_grabbed(bar, event, window))
        return 1;
    if (event->type == sfEvtMouseButtonReleased
        && event->mouseButton.button == sfMouseLeft && bar->grabbed)
        bar->grabbed = 0;
    if (event->type == sfEvtMouseMoved && bar->grabbed)
        update_pos(bar, event, window);
    return 0;
}
