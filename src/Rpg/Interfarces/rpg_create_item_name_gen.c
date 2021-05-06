/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** name_gen
*/

#include "Rpg/rpg.h"

static char *const NAME[] = {" Pebble", " Stone", " Jade", " Amber", " Jewel",
    " Papyrus", " Scroll", " Book", " Manuscipt", " Grimoire", " Pebble",
    " Stone", " Jade", " Amber", " Jewel", " Papyrus", " Scroll", " Book",
    " Manuscipt", " Grimoire"};

static char *const PREFIX[] = {"Boring", "Vicious", "Bloody", "Magical",
    "Intense", "Mysterious", "Sweet", "Painful", "Lucky", "Corrupted",
    "Vengeful", "Strong", "Glorious", "Blessed", "Holy", "Deadly",
    "Imaginative", "Tal Kasha's", "Kralamoure's", "Impressive", "Crazy", NULL};

static char *const SUFFFIX[] = {" Of The Whale", " Of Death", " Of the Squid",
    "'s Madness", " Of Herpege", " Of Dransea's cult", " From Salmon Sea",
    " Of CrossBowBoy", NULL};

static char *const FULL_NAME[] = {"The Untold", "The Dransea",
    "Bloody Herpege Relic", "The Crazy Salmon", "CrossBowBoy Special Gift",
    "Aymeric Generosity"
    "Impatience of Jeremy",
    "Pierrick Wisdom", NULL};

static int rpg_create_item_name_copy(char *dest, char *src)
{
    int i = 0;

    if (dest == NULL || src == NULL)
        return (0);
    for (; src[i]; i++)
        dest[i] = src[i];
    return (i);
}

static size_t array_lenght(char *const *tab)
{
    size_t i = 0;

    while (tab[i])
        i++;
    return (i);
}

extern void rpg_create_item_name_generator(item_t *item, int level)
{
    item->name = malloc(sizeof(char) * 70);
    int index = 0;

    for (uint i = 0; i != 70; i++)
        item->name[i] = '\0';
    if (level == 10 && item->rarity == LEGENDARY) {
        rpg_create_item_name_copy(
            item->name, FULL_NAME[rand() % array_lenght(FULL_NAME)]);
        return;
    }
    index += rpg_create_item_name_copy(
        item->name, PREFIX[rand() % array_lenght(PREFIX)]);
    index += rpg_create_item_name_copy(
        &item->name[index], NAME[item->elem * 5 + item->rarity]);
    rpg_create_item_name_copy(
        &item->name[index], SUFFFIX[rand() % array_lenght(SUFFFIX)]);
}
