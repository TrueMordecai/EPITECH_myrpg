/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** zone open file
*/

#include <libmy/io/iostream.h>
#include <libmy/printf.h>
#include <stdlib.h>

#include "Rpg/Map/physic.h"
#include "Rpg/Map/zone.h"
#include "functions.h"

static void read_infos(zone_t *zone, char *file_content, size_t *i)
{
    sfVector2i size;
    sfVector2i pos;

    zone->nb_layers = get_number_pass(file_content, i) - 2;
    zone->size.x = get_number_pass(file_content, i);
    zone->size.y = get_number_pass(file_content, i);
    zone_init(zone, zone->nb_layers, zone->size);
    for (int layer = 0; layer < zone->nb_layers; layer++) {
        pos.x = get_number_pass(file_content, i);
        pos.y = get_number_pass(file_content, i);
        size.x = get_number_pass(file_content, i);
        size.y = get_number_pass(file_content, i);
        layer_init(zone->layers[layer], size, pos);
    }
}

int get_nb_pass(unsigned char *content, size_t *i, int pass)
{
    int layer = 0;

    while (content[*i] > 2) {
        layer *= 253;
        layer += content[*i] - 3;
        (*i)++;
    }
    if (pass)
        (*i)++;
    return layer;
}

static void read_pos(
    zone_t *zone, sfVector2i pos, size_t *i, unsigned char *content)
{
    int layer;
    int tile;

    if (content[*i] < 3)
        return;
    do {
        if (content[*i] == 1)
            (*i)++;
        layer = get_nb_pass(content, i, 1);
        tile = get_nb_pass(content, i, 0);
        if (layer > 1 && layer - 2 < zone->nb_layers)
            layer_place_tile(zone->layers[layer - 2], pos, tile);
        if (layer == 0 && zone->nb_layers >= 0)
            physic_add_shaped_tile(zone, (sfVector2i){pos.x, pos.y}, tile);
        if (layer == 1 && zone->nb_layers >= 1)
            zone_add_special(zone, (sfVector2i){pos.x, pos.y}, tile);
    } while (content[*i] == 1);
}

static char *zone_read_file(char const *path, size_t *file_size)
{
    my_iostream_t file;
    char *file_content;

    if (my_fopen(path, "r", &file)
        || my_fset_buffer(malloc(1024), 1024, &free, &file)) {
        my_fprintf(MY_STDERR, "Cannot open zone file: %#s\n", path);
        return NULL;
    }
    file_content = my_fread_to_string(SIZE_MAX, file_size, &file);
    if (file_content == NULL)
        my_fprintf(MY_STDERR, "Cannot read zone file: %#s\n", path);
    my_fclose(&file);
    return file_content;
}

int zone_init_from_file(zone_t *zone, int id, int door, int mother)
{
    size_t file_size;
    char *file_content = zone_read_file(ALL_ZONE_NAMES[id], &file_size);
    size_t offset = 0;

    if (file_content == NULL)
        return 1;
    read_infos(zone, file_content, &offset);
    for (int x = 0; x < zone->size.x; x++) {
        for (int y = 0; y < zone->size.y; y++) {
            read_pos(zone, (sfVector2i){x, y}, &offset,
                (unsigned char *)file_content);
            offset += (file_content[offset] != 0);
        }
    }
    zone_sort_layers(zone);
    free(file_content);
    battle_compute_layer(&zone->battle);
    zone->id = id;
    zone->mother_zone = mother;
    zone_place_at_door(zone, door);
    return 0;
}
