/*
** EPITECH PROJECT, 2021
** MyRPG - Quests
** File description:
** quests.c
*/

#include <SFML/Graphics.h>
#include <libmy/parsing.h>
#include "Rpg/Quests/quests.h"
#include "Rpg/rpg.h"

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

    while (quests_data->list[nb_quest])
        nb_quest++;
    quests_data->quests = malloc(sizeof(quest_t) * nb_quest);
    for (int i = 0; quests_data->list[i] != NULL; i++) {
        quests_data->quests[i].quest_type = my_getnbr(quests_data->list[i]);
        parse_quest_info(quests_data, i);
    }
    quests_data->nb_quests = nb_quest;
}

void create_dialogue_bg(rpg_t *rpg, dialogue_bg_t *dialogue)
{
    dialogue->bg = sfSprite_create();
    sfSprite_setScale(
        dialogue->bg, (sfVector2f){SL(rpg) / (2 / 3.f), SL(rpg) / (2 / 3.f)});
    sfSprite_setTexture(dialogue->bg,
        get_texture(&rpg->state->game_data->assets, "dialogue_bg"), sfTrue);
    sfSprite_setPosition(
        dialogue->bg, (sfVector2f){260.25 * SL(rpg), 765 * SL(rpg)});
}

void create_dialogue_font(rpg_t *rpg, dialogue_bg_t *dialogue)
{
    sfFont *font;

    font = get_font(&rpg->state->game_data->assets, "pixel2");
    dialogue->text = sfText_create();
    sfText_setFont(dialogue->text, font);
    sfText_setCharacterSize(dialogue->text, 30 * SL(rpg));
    sfText_setFillColor(dialogue->text, sfBlack);
    sfText_setPosition(dialogue->text,
        (sfVector2f){(int)(368.25 * SL(rpg)), (int)(802.5 * SL(rpg))});
}

int quests_init(quest_list_t *quests_data, char *filepath)
{
    quests_data->filepath = filepath;
    if (setup_data(quests_data) == -1)
        return (-1);
    if (check_file_error(quests_data->list) == -1)
        return (-1);
    setup_quest_by_id(quests_data);
    free_all(quests_data);
    quests_data->current_quest = 0;
    create_dialogue_bg(quests_data->rpg, &quests_data->dialogue);
    create_dialogue_font(quests_data->rpg, &quests_data->dialogue);
    return 0;
}
