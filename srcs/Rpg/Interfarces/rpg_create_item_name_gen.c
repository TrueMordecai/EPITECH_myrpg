/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** name_gen
*/

#include "Rpg/rpg.h"

static char *const NAME[] = {
    " Pebble", " Stone", " Jade", " Amber", " Jewel",
    " Papyrus", " Scroll", " Book", " Manuscipt", " Grimoire",
    " Pebble", " Stone", " Jade", " Amber", " Jewel",
    " Papyrus", " Scroll", " Book", " Manuscipt", " Grimoire"
};

static char *const PREFIX[] = {
    "Boring", "Vicious", "Bloody", "Magical", "Intense", "Mysterious", "Sweet",
    "Painful", "Lucky", "Corrupted", "Vengeful", "Strong", "Glorious",
    "Blessed", "Holy", "Deadly", "Imaginative", "Tal Kasha's", "Kralamoure's",
    "Ipressive", "Aymeric special "
};

static char *const SUFFFIX[] ={
    " Of The Whale", " Of Death", " Of Jeremy", " Of the Squid", "'s Madness"
};

int my_strcpy(char *dest, char *src)
{
    int i = 0;

    if (dest == NULL || src == NULL)
        return (0);
    for (; src[i]; i++)
        dest[i] = src[i];
    return (i);
}

extern void rpg_create_item_name_generator(item_t *item, int level)
{
    item->name = malloc(sizeof(char) * 50);
    int index = 0;

    (void)level;
    for (uint i = 0; i != 50; i++)
        item->name[i] = '\0';
    index += my_strcpy(item->name, PREFIX[rand() % 20]);
    index += my_strcpy(&item->name[index], NAME[item->elem * 5 + item->rarity]);
    my_strcpy(&item->name[index], SUFFFIX[rand() % 5]);
}

