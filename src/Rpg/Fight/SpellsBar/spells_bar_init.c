/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** spells_bar_init
*/

#include "Rpg/Fight/fight.h"
#include "Rpg/rpg.h"
#include "Rpg/Fight/spells_bar.h"

static void init_spell_frame(spells_bar_t *bar, int x, int y)
{
    asset_manager_t *assets = &bar->fight->rpg->state->game_data->assets;
    sfRectangleShape *rect;

    bar->frames[x + y * SPELLS_BAR_WIDTH] = sfRectangleShape_create();
    rect = bar->frames[x + y * SPELLS_BAR_WIDTH];
    sfRectangleShape_setSize(rect, (sfVector2f){FRAME_WIDTH, FRAME_WIDTH});
    sfRectangleShape_setPosition(
        rect, (sfVector2f){x * FRAME_WIDTH, y * FRAME_WIDTH});
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineColor(rect, sfBlack);
    sfRectangleShape_setOutlineThickness(rect, -1);
    sfRectangleShape_setTexture(rect, get_texture(assets, "spells"), 1);
}

static void init_rects(spells_bar_t *bar)
{
    sfRectangleShape_setSize(bar->background,
        (sfVector2f){
            FRAME_WIDTH * SPELLS_BAR_WIDTH, FRAME_WIDTH * SPELLS_BAR_HEIGHT});
    sfRectangleShape_setFillColor(
        bar->background, sfColor_fromRGBA(100, 100, 100, 150));
    sfRectangleShape_setPosition(
        bar->move_bar, (sfVector2f){0, -FRAME_WIDTH / 10 - 15});
    sfRectangleShape_setSize(bar->move_bar,
        (sfVector2f){FRAME_WIDTH * SPELLS_BAR_WIDTH, FRAME_WIDTH / 10 + 15});
    sfRectangleShape_setFillColor(
        bar->move_bar, sfColor_fromRGBA(100, 100, 100, 255));
}

static void init_text(sfText *text, sfFont *font, char *str, sfVector2f pos)
{
    sfText_setCharacterSize(text, 18);
    sfText_setFont(text, font);
    sfText_setString(text, str);
    sfText_setPosition(text, pos);
}

static void init_life_pa_pm(spells_bar_t *bar)
{
    float len = SPELLS_BAR_WIDTH * FRAME_WIDTH;
    sfFont *font =
        get_font(&bar->fight->rpg->state->game_data->assets, "roboto_font");

    bar->life = sfRectangleShape_create();
    bar->life_bg = sfRectangleShape_create();
    bar->text_pa = sfText_create();
    bar->text_pm = sfText_create();
    sfRectangleShape_setFillColor(bar->life, sfRed);
    sfRectangleShape_setPosition(bar->life, (sfVector2f){len * 0.2, -17.5});
    sfRectangleShape_setSize(bar->life, (sfVector2f){len * 0.6, 15});
    sfRectangleShape_setFillColor(bar->life_bg, sfTransparent);
    sfRectangleShape_setPosition(bar->life_bg, (sfVector2f){len * 0.2, -17.5});
    sfRectangleShape_setSize(bar->life_bg, (sfVector2f){len * 0.6, 15});
    sfRectangleShape_setOutlineColor(bar->life_bg, sfBlack);
    sfRectangleShape_setOutlineThickness(bar->life_bg, -1);
    init_text(bar->text_pa, font, "6/6 PA", (sfVector2f){len / 20.0, -21});
    sfText_setFillColor(bar->text_pa, sfBlue);
    init_text(
        bar->text_pm, font, "6/6 PM", (sfVector2f){16.5 * len / 20.0, -21});
    sfText_setFillColor(bar->text_pm, sfGreen);
}

void spells_bar_init(spells_bar_t *bar, fight_t *fight)
{
    bar->fight = fight;
    bar->grabbed = 0;
    bar->last_entity = NULL;
    bar->background = sfRectangleShape_create();
    bar->move_bar = sfRectangleShape_create();
    bar->current_frame = -1;
    bar->view = sfView_create();
    bar->nb_frames = SPELLS_BAR_WIDTH * SPELLS_BAR_HEIGHT;
    bar->frames = malloc(sizeof(sfRectangleShape *) * bar->nb_frames);
    init_rects(bar);
    init_life_pa_pm(bar);
    for (int x = 0; x < SPELLS_BAR_WIDTH; x++)
        for (int y = 0; y < SPELLS_BAR_HEIGHT; y++)
            init_spell_frame(bar, x, y);
    sfView_setSize(bar->view, (sfVector2f){1280, 720});
    sfView_setCenter(bar->view, (sfVector2f){640, 360});
    sfView_move(bar->view,
        (sfVector2f){(FRAME_WIDTH * SPELLS_BAR_WIDTH - 1280) / 2.f,
            FRAME_WIDTH * SPELLS_BAR_HEIGHT - 720});
}