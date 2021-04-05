/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Game engine - audio manager
*/

#include "GameEngine/game_head.h"

static void load_sounds(audio_manager_t *manager)
{
    //load_sound(manager, "mouse_click", "res/Sounds/sound_name.wav");
}

static void load_musics(audio_manager_t *manager)
{
    //load_music(manager, "menu", "res/Musics/music_name.ogg");
}

void load_audio(audio_manager_t *manager)
{
    load_sounds(manager);
    load_musics(manager);
    return;
}