/*
** EPITECH PROJECT, 2021
** MyRPG - Quests
** File description:
** quests.c
*/

#include <libmy/parsing.h>

#include <SFML/Graphics.h>
#include "Rpg/Quests/quests.h"

void free_all(quest_list_t *quests_data)
{
    int i = 0;

    for (; quests_data->list[i] != NULL; i++) {
        free(quests_data->list[i]);
    }
    free(quests_data->list[i]);
    free(quests_data->list);
}

void setup_quest_by_id(quest_list_t *quests_data)
{
    int nb_quest = 0;

    for (; quests_data->list[nb_quest] != NULL; nb_quest++)
        ;
    quests_data->quests = malloc(sizeof(quest_t) * nb_quest);
    for (int i = 0; quests_data->list[i] != NULL; i++) {
        quests_data->quests[i].quest_type = my_getnbr(quests_data->list[i]);
        parse_quest_info(quests_data, i);
    }
    quests_data->nb_quests = nb_quest;
}

void create_dialogue_bg(dialogue_bg_t *dialogue)
{
    sfVector2f center = {933 / 2, 166 / 2};
    sfTexture *bg_texture;
    sfVector2f shift = {640, 720 / 1.2};

    bg_texture = sfTexture_createFromFile(\
        "./assets/Textures/dialogue_bg.png", NULL);
    dialogue->bg = sfSprite_create();
    sfSprite_setTexture(dialogue->bg, bg_texture, sfTrue);
    sfSprite_setOrigin(dialogue->bg, center);
    sfSprite_setPosition(dialogue->bg, shift);
}

void create_dialogue_font(dialogue_bg_t *dialogue)
{
    sfFont *font;

    font = sfFont_createFromFile("./assets/Fonts/pixel2.ttf");
    dialogue->text = sfText_create();
    sfText_setFont(dialogue->text, font);
    sfText_setOrigin(dialogue->text, (sfVector2f){50, 50});
    sfText_setCharacterSize(dialogue->text, 20);
    sfText_setFillColor(dialogue->text, (sfColor){0, 0, 0, 255});
    sfText_setPosition(dialogue->text, (sfVector2f){300, 720 / 1.2});
}

int quests_init(quest_list_t *quests_data, char *filepath)
{
    quests_data->filepath = filepath;
    if (setup_data(quests_data) == -1)
        return (-1);
    setup_quest_by_id(quests_data);
    free_all(quests_data);
    quests_data->current_quest = 0;
    create_dialogue_bg(&quests_data->dialogue);
    create_dialogue_font(&quests_data->dialogue);
    return 0;
}
