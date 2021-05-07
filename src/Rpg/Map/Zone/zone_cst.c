/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** zones const
*/

#include "Rpg/rpg.h"

const int ZONE_START = 0;

const int NB_MAIN_ZONES = 3;
const char *ALL_ZONE_NAMES[5] = {"assets/Zones/zone_village",
    "assets/Zones/zone_cave", "assets/Zones/zone_boss",
    "assets/Zones/zone_prison"};

const sfVector2i ZONE_0_LINKS[1] = {{1, 2}};
const sfVector2i ZONE_1_LINKS[4] = {{1, 3}, {2, 0}, {0, 0}, {1, 0}};
const sfVector2i ZONE_2_LINKS[1] = {{1, 1}};
const sfVector2i *ZONES_LINKS[3] = {ZONE_0_LINKS, ZONE_1_LINKS, ZONE_2_LINKS};

const int SUBZONES_0_IDS[1] = {NB_MAIN_ZONES};
const int SUBZONES_1_IDS[1];
const int SUBZONES_2_IDS[1];
const int *SUB_ZONES_IDS[3] = {SUBZONES_0_IDS, SUBZONES_1_IDS, SUBZONES_2_IDS};
