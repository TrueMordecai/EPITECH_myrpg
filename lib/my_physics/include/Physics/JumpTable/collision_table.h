/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - Collision jump table
*/

#ifndef PHYSICS_COLLISION_JUMP_TABLE_H
#define PHYSICS_COLLISION_JUMP_TABLE_H

struct pe_manifold_t;

// define colliders using a typedef so the 'const' qualifier of
// pe_collide_table gets applied to the variable and NOT the function pointers'
// return type.
typedef char (*pe_collider_t)(struct pe_manifold_t *);

extern const pe_collider_t pe_collide_table[2][2];

#endif /* !PHYSICS_COLLISION_JUMP_TABLE_H */
