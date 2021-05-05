/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** zones const
*/

#include "Rpg/rpg.h"

const int ZONE_START = 0;
const int ZONE_HOUSE = 1;

const int NB_MAIN_ZONES = 2;
const char *ALL_ZONE_NAMES[5] = {"assets/Zones/zone_test",
    "assets/Zones/zone_test2", "assets/Zones/house_test",
    "assets/Zones/house_test2", "assets/Zones/house_test3"};

const sfVector2i ZONE_0_LINKS[1] = {{1, 0}};
const sfVector2i ZONE_1_LINKS[1] = {{0, 0}};
const sfVector2i *ZONES_LINKS[2] = {ZONE_0_LINKS, ZONE_1_LINKS};

const int SUBZONES_0_IDS[3] = {
    NB_MAIN_ZONES, NB_MAIN_ZONES + 1, NB_MAIN_ZONES + 2};
const int SUBZONES_1_IDS[1];
const int *SUB_ZONES_IDS[2] = {SUBZONES_0_IDS, SUBZONES_1_IDS};
