/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** stats_compute_damages
*/

#include <stdio.h>
#include "Rpg/Entities/stats.h"
#include "Rpg/InfoBox/infobox_entity.h"
#include "functions.h"

int stats_compute_damages(stats_t *from, stats_t *to, int element, int value)
{
    return (value * (1 + MAX(-0.5, from->elements[element] / 20.f)))
        * ((100 - (MIN(100, to->resistances[element]))) / 100.0);
}