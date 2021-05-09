/*
** EPITECH PROJECT, 2021
** MyRPG - Quests
** File description:
** The questing system
*/

#ifndef __RPG_QUESTS_H__
#define __RPG_QUESTS_H__

#include <SFML/Graphics/Types.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct rpg rpg_t;

enum quest_type_e {
    QUEST_KILL = 1,
    QUEST_GO = 2,
    QUEST_TALK = 3,
    QUEST_GET = 4
};

typedef struct talk_to_pnj {
    int pnj_id;
} talk_to_pnj_t;

typedef struct kill_monster {
    int count;
    int type_id;
} kill_monster_t;

typedef struct get_item {
    int count;
    int type_id;
} get_item_t;

typedef struct go {
    int zone_id;
} go_t;

typedef struct quest {
    char *context;
    int quest_type;
    union {
        kill_monster_t kill_monster;
        go_t go_zone;
        talk_to_pnj_t talk_to_pnj;
        get_item_t get_item;
    };
    int state;
} quest_t;

typedef struct dialogue_bg {
    bool is_talking;
    sfSprite *bg;
    sfFont *font;
    sfText *text;
} dialogue_bg_t;

typedef struct quests {
    char *filepath;
    char **list;
    dialogue_bg_t dialogue;
    quest_t *quests;
    size_t nb_quests;
    size_t file_size;
    size_t current_quest;
    rpg_t *rpg;
} quest_list_t;

int get_file_id(char const *file_path);

int get_file_size(char const *file_path);

char *my_file_content_to_str(char const *file_path);

int get_nb_line(char *filecontent);

int setup_data(quest_list_t *file_info);

int quests_init(quest_list_t *quests_data, char *filepath);
quest_t *quests_get_current(quest_list_t *list);
int quests_validate(quest_list_t *quest_list);
void quests_destroy(quest_list_t *quests);
void parse_quest_info(quest_list_t *quest_data, int index_quest);

void quests_draw(rpg_t *rpg);

int check_file_error(char **quests_list);

#endif // !defined(__RPG_QUESTS_H__)
