/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** all my lib functions prototype
*/

#ifndef MY_H_
#define MY_H_
void my_putchar(char c);
int my_isneg(int n);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *array, int size);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *str);
char *my_strncpy(char *dest, char const *str, int n);
char *my_revstr(char *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintablet(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_isupper(char c);
int is_ok(char c);
int my_is_letter(char c);
int my_is_lower_case(char c);
int my_isnum(char c);
int my_is_printable(char c);
int my_isupper(char c);
int check_to_find(char const *s1, char const *s2, int i);
int count_words(char const *str);
int is_new_word(char const *str);
char *str_malloc(char const *src);
int is_sep(char c);
int my_isalpha(char c);
int my_is_lower(char c);
int my_is_num(char c);
char *my_strdup(char const *src);
int my_str_isalpha(char *str);
#endif
