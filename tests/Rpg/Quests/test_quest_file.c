/*
** EPITECH PROJECT, 2021
** MyRPG unit tests
** File description:
** Tests the cfg_file functions
*/

#include <criterion/criterion.h>

#include <signal.h>

#include "Rpg/rpg.h"

Test(check_file_error, normal_use, .signal=SIGSEGV, .description="expected signal == SIGSEGV")
{
    char **quests_list = {strdup("2 0 this is the first quest"), strdup("2 0 this is the second quest")};
    int answer = check_file_error(quests_list);
    cr_assert_eq(answer, 0);
}

Test(check_file_error, error_use, .signal=SIGSEGV, .description="expected signal == SIGSEGV")
{
    char **quests_list = {strdup("0 0 this is the first quest"), strdup("0 0 this is the second quest")};
    int answer = check_file_error(quests_list);
    cr_assert_eq(answer, 0);
}

Test(check_file_error, error_use_2, .signal=SIGSEGV, .description="expected signal == SIGSEGV")
{
    char **quests_list = {strdup("this is the first quest"), strdup("this is the second quest")};
    int answer = check_file_error(quests_list);
    cr_assert_eq(answer, 0);
}

Test(check_file_error, null_use, .signal=SIGSEGV, .description="expected signal == SIGSEGV")
{
    char **quests_list = {NULL, strdup("1 0 this is the second quest")};
    int answer = check_file_error(quests_list);
    cr_assert_eq(answer, 0);
}

Test(check_file_error, correct_kill_use, .signal=SIGSEGV, .description="expected signal == SIGSEGV")
{
    char **quests_list = {strdup("1 5 1 this is the first quest"), strdup("1 1 5 this is the second quest")};
    int answer = check_file_error(quests_list);
    cr_assert_eq(answer, 0);
}
