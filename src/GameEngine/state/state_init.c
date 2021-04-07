/*
** EPITECH PROJECT, 2021
** MyRPG - Game Engine
** File description:
** Initializes the common state data
*/

#include <libmy/collections.h>
#include <stdalign.h>

#include "Drawables/drawable.h"
#include "GameEngine/state.h"

static void uchar_key_hash(my_hasher_t *hasher, unsigned char const *key)
{
    my_hasher_write_u8(hasher, *key);
}

static int uchar_key_cmp(
    unsigned char const *key_a, unsigned char const *key_b)
{
    return ((int)*key_a) - ((int)*key_b);
}

static const my_map_kvtypes_t LAYER_KVTYPES = {
    .key_size = sizeof(unsigned char),
    .key_align = alignof(unsigned char),
    .value_size = sizeof(drawable_t),
    .value_align = alignof(drawable_t),
    .hash = (my_map_hash_key_t)&uchar_key_hash,
    .compare = (my_map_compare_keys_t)&uchar_key_cmp,
    .value_drop = (my_map_drop_t)&drawable_destroy,
};

int state_init(state_t *state, state_id_t state_id, size_t layer_count)
{
    if (state == NULL
        || my_vec_init_capacity(
            &state->draw_layers, layer_count, sizeof(my_hash_map_t)))
        return 1;
    for (size_t i = 0; i < layer_count; ++i) {
        my_hash_map_t *layer = my_vec_get(&state->draw_layers, i);

        my_hash_map_init(layer, &LAYER_KVTYPES);
    }
    state->draw_layers.length = layer_count;
    state->state_id = state_id;
    return 0;
}
