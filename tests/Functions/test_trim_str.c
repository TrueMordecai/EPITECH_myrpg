/*
** EPITECH PROJECT, 2021
** MyRPG unit tests
** File description:
** Tests the test_trim_str function
*/

#include <criterion/criterion.h>

#include "functions.h"

Test(trim_str, null_bytes_buffer)
{
    char buf[10] = {0};
    char const *start = buf;
    char const *end = buf;

    cr_assert_eq(trim_str(&start, &end), buf);
    cr_assert_eq(start, buf);
    cr_assert_eq(end, buf);
    start = buf + 2;
    end = buf + 7;
    cr_assert_eq(trim_str(&start, &end), buf + 2);
    cr_assert_eq(start, buf + 2);
    cr_assert_eq(end, buf + 7);
    start = buf + 8;
    end = buf + 1;
    cr_assert_eq(trim_str(&start, &end), buf + 1);
    cr_assert_eq(start, buf + 1);
    cr_assert_eq(end, buf + 8);
}

Test(trim_str, only_whitespace)
{
    char const *str = "   \n\t\r\n\t\v  \r\n";
    char const *start = str;
    char const *end = str + 13;

    cr_assert_eq(trim_str(&start, &end), str + 13);
    cr_assert_eq(start, str + 13);
    cr_assert_eq(end, str + 13);
}

Test(trim_str, normal_string_no_whitespace)
{
    char const *str = "./tests/Functions/test_trim_str.c";
    char const *start = str;
    char const *end = str + 33;

    cr_assert_eq(trim_str(&start, &end), str);
    cr_assert_eq(start, str);
    cr_assert_eq(end, str + 33);
    start = str + 17;
    end = str + 8;
    cr_assert_eq(trim_str(&start, &end), str + 8);
    start = str + 8;
    end = str + 17;
}

Test(trim_str, normal_string_with_whitespace)
{
    char const *str = " \n \t\vThis is a:\nTest \f    ";
    char const *start = str;
    char const *end = str + 26;

    cr_assert_eq(trim_str(&start, &end), str + 5);
    cr_assert_eq(start, str + 5);
    cr_assert_eq(end, str + 20);
}
