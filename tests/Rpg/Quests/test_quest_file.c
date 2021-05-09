/*
** EPITECH PROJECT, 2021
** MyRPG unit tests
** File description:
** Tests the cfg_file functions
*/

#include <criterion/criterion.h>

#include "Rpg/rpg.h"
/*
Test(cfg_file_drop, null_cfg)
{
    cfg_file_drop(NULL);
}

Test(cfg_file_drop, empty_cfg)
{
    cfg_file_t cfg;

    cfg_file_init(&cfg);
    cfg_file_drop(&cfg);
}

Test(cfg_file_drop, filled_cfg)
{
    char const src[] = "K=V\nkeyes=dead";
    my_iostream_t input;
    cfg_file_t cfg;

    cfg_file_init(&cfg);
    my_finit_input_memory(src, sizeof(src) / sizeof(*src), &input);
    cr_assert_eq(0, cfg_file_read_from_stream(&cfg, &input, true));
    cfg_file_drop(&cfg);
}

Test(cfg_file_input_memory, one_line)
{
    char const src[] = "K=V";
    my_iostream_t input;
    cfg_file_t cfg;
    char const *val;

    cfg_file_init(&cfg);
    my_finit_input_memory(src, sizeof(src) / sizeof(*src), &input);
    cr_assert_eq(0, cfg_file_read_from_stream(&cfg, &input, true));
    cr_assert(cfg_file_get_str_value(&cfg, "K", &val));
    cr_assert_str_eq(val, "V");
    cfg_file_drop(&cfg);
}

Test(cfg_file_input_memory, one_line_with_padding)
{
    char const src[] = " K   \t =  V \v";
    my_iostream_t input;
    cfg_file_t cfg;
    char const *val;

    cfg_file_init(&cfg);
    my_finit_input_memory(src, sizeof(src) / sizeof(*src), &input);
    cr_assert_eq(0, cfg_file_read_from_stream(&cfg, &input, true));
    cr_assert(cfg_file_get_str_value(&cfg, "K", &val));
    cr_assert_str_eq(val, "V");
    cfg_file_drop(&cfg);
}

Test(cfg_file_input_memory, multi_line_with_comments)
{
    char const src[] = {"SIMPLE=OK\n\vWITH COMMENT = yep "
                        "#indeed\n\n\t\v\vOMEGALEL =       KEKISTAN\n"};
    my_iostream_t input;
    cfg_file_t cfg;
    char const *val;

    cfg_file_init(&cfg);
    my_finit_input_memory(src, sizeof(src) / sizeof(*src), &input);
    cr_assert_eq(0, cfg_file_read_from_stream(&cfg, &input, true));
    cr_assert(cfg_file_get_str_value(&cfg, "SIMPLE", &val));
    cr_assert_str_eq(val, "OK");
    cr_assert(cfg_file_get_str_value(&cfg, "WITH COMMENT", &val));
    cr_assert_str_eq(val, "yep");
    cr_assert(cfg_file_get_str_value(&cfg, "OMEGALEL", &val));
    cr_assert_str_eq(val, "KEKISTAN");
    cfg_file_drop(&cfg);
}
*/