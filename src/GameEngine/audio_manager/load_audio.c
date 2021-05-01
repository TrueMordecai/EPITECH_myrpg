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
    load_sound(manager, "select", "assets/Sounds/Menus/Menu1.wav");
    load_sound(manager, "pass_turn", "assets/Sounds/Fight/MiniImpact.wav");
    load_sound(manager, "fight_lose", "assets/Sounds/Fight/GameOver.wav");
    load_sound(manager, "fight_win", "assets/Sounds/Fight/Success3.wav");
    load_sound(manager, "spell_attack", "assets/Sounds/Fight/Hit.wav");
    load_sound(manager, "spell_heal", "assets/Sounds/Fight/Gold1.wav");
    load_sound(manager, "spell_effect", "assets/Sounds/Fight/Bonus.wav");
    load_sound(manager, "spell_debuff", "assets/Sounds/Fight/PowerUp1.wav");
    load_sound(manager, "entity_death", "assets/Sounds/Fight/Spirit.wav");
    load_sound(manager, "move", "assets/Sounds/Fight/Fx.wav");
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
