/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Game engine - audio manager
*/

#include "GameEngine/game_head.h"

static void load_sounds(audio_manager_t *manager)
{
    load_sound(manager, "click", "assets/Sounds/Menus/click.wav");
}

static void load_music_tracks(audio_manager_t *manager)
{
    load_music(manager, "menu", "assets/Musics/12 - Temple.ogg");
    load_music(manager, "game", "assets/Musics/4 - Village.ogg");
    load_music(manager, "fight", "assets/Musics/17 - Fight.ogg");
}

void load_audio(audio_manager_t *manager)
{
    load_sounds(manager);
    load_music_tracks(manager);
    return;
}
