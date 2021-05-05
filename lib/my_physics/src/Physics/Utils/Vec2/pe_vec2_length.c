/*
** EPITECH PROJECT, 2020
** MyPhysics
** File description:
** Physics - vec2f compute length
*/

#include <math.h>
#include "Physics/physics.h"

float pe_vec2f_length(pe_vec2f_t v)
{
    return sqrtf(pe_vec2f_length_squared(v));
}

float pe_vec2i_length(pe_vec2i_t v)
{
    return sqrtf(pe_vec2i_length_squared(v));
}

float pe_vec2u_length(pe_vec2u_t v)
{
    return sqrtf(pe_vec2u_length_squared(v));
}
