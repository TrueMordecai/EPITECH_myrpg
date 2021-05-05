/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** spells_init
*/

#include <stdalign.h>
#include <libmy/collections/hash_map.h>

#include "Rpg/Fight/spell.h"
#include "Rpg/rpg.h"

static void spell_drop(spell_base_t **spell)
{
    if (!(*spell))
        return;
    free((*spell)->name);
    free(*spell);
}

static const my_map_kvtypes_t SPELLS_KVTYPES = {
    .key_size = sizeof(char *),
    .key_align = alignof(char *),
    .value_size = sizeof(spell_base_t *),
    .value_align = alignof(spell_base_t *),
    .hash = MY_HASH_MAP_CSTR_HASH,
    .compare = MY_HASH_MAP_CSTR_CMP,
    .value_drop = (my_map_drop_t)&spell_drop,
};

static void load_spell(rpg_t *rpg, char const *name, char *path)
{
    spell_base_t *spell = NULL;

    if (my_hash_map_contains(&rpg->spells, &name))
        return;
    spell = spell_create_from_file(path);
    if (!spell)
        return;
    my_hash_map_insert(&rpg->spells, &name, &spell);
}

static void load_spells(rpg_t *rpg)
{
    load_spell(rpg, "punch", "assets/Spells/a_punch.spell");
    load_spell(rpg, "spit_fire", "assets/Spells/a_spit_fire.spell");
    load_spell(rpg, "spit", "assets/Spells/a_spit.spell");
    load_spell(rpg, "debuff_all", "assets/Spells/d_debuff_all.spell");
    load_spell(rpg, "debuff_boost", "assets/Spells/d_debuff_boost.spell");
    load_spell(rpg, "debuff_damage", "assets/Spells/d_debuff_damage.spell");
    load_spell(rpg, "burn", "assets/Spells/e_burn.spell");
    load_spell(rpg, "jump", "assets/Spells/e_jump.spell");
    load_spell(rpg, "heal_zone", "assets/Spells/h_heal_zone.spell");
    load_spell(rpg, "heal", "assets/Spells/h_heal.spell");
}

spell_base_t *get_spell(rpg_t *rpg, char const *name)
{
    spell_base_t **spell = my_hash_map_get(&rpg->spells, &name);

    return (spell == NULL) ? NULL : (*spell);
}

void spells_init(rpg_t *rpg)
{
    my_hash_map_init(&rpg->spells, &SPELLS_KVTYPES);
    load_spells(rpg);
}
