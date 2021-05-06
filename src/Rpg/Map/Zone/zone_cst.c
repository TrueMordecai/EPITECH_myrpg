/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** zones const
*/

#include "Rpg/rpg.h"

const int ZONE_START = 0;

const int NB_MAIN_ZONES = 2;
const char *ALL_ZONE_NAMES[5] = {"assets/Zones/zone_village", //"../../Tek1/B-MUL/map-editor/res/Map/zone_test",
    "assets/Zones/zone_cave", "assets/Zones/zone_prison"};

const sfVector2i ZONE_0_LINKS[1] = {{1, 2}};
const sfVector2i ZONE_1_LINKS[4] = {{1, 3}, {0, 0}, {0, 0}, {1, 0}};
const sfVector2i *ZONES_LINKS[2] = {ZONE_0_LINKS, ZONE_1_LINKS};

const int SUBZONES_0_IDS[1] = {
    NB_MAIN_ZONES};
const int SUBZONES_1_IDS[1];
const int *SUB_ZONES_IDS[2] = {SUBZONES_0_IDS, SUBZONES_1_IDS};
