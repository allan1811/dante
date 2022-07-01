/*
** EPITECH PROJECT, 2021
** MY.H
** File description:
** my.h for solver
*/
#include <unistd.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <stdbool.h>

#ifndef MY_H_
    #define MY_H_

enum t {
    WALL,
    PATH,
    FREE,
    START,
    FINISH,
    END
};

typedef struct stack_s stack_t;

typedef struct nodelist {
    stack_t *cell;
    struct nodelist *next;
}nodelist, *list_node;

typedef struct stack_s {
    int x;
    int y;
    float loc;
    float glob;
    struct stack_s *parent;
    int t;
    bool visited;
    list_node nbr;
} stack_t;

typedef struct map {
    FILE *fp;
    int x;
    int y;
    int perfect;
    int size;
    char *mapstart;
    char **map;
    list_node stack;
    stack_t **cell_array;
} map_t;

//! lib
char *my_int_to_str(int nbr);
void my_put_nbr(long long int nb);
void my_putchar(char c);
void my_putstr(char *str);
char *my_revstr(char *str);
int my_str_to_int(char *str);
int my_strlen(char *str);
int my_strstrlen(char **str);
int my_strcmp(char *fst, char *snd);
int my_strncmp(char *fst, char *snd, int n);
char *my_strncat(char *dest, char const *src, int n);
char *my_strcat(char *dest, char *src);

void print_arg(char **array);
list_node new_list(void);

char **my_str_to_word_array(char *str);
int word_len(char *str, int i);
int count(char *str);
int is_charac(char c, int status);

char **my_str_to_word_array_sep(char *str, char sep);
list_node add_back(list_node li, stack_t *cell);
int count_sep(char *str, char sep);
int is_charac_sep(char c, char sep);
char *my_strncpy(char *dest, char *src, int n);
list_node remove_front(list_node list);
int my_sqrt(float nb);
int my_power(int nb, int p);
bool empty(list_node list);

void disp_stdarg(char s, va_list list);
void disp2(char s, va_list list);
void disp3(char s, va_list list);
void disp4(char s, va_list list);
void disp5(char s, va_list list);
void disps(char str);
void my_printf(char *str, ...);
void my_int_to_bin(int n);
void my_int_to_hex(int n);
void my_int_to_oct(int n);
//!solver
void check_neighb(map_t *map, stack_t *current, list_node not_visit);
void is_block(char **map);
void astar_decla(map_t *map);
int main(int ac, char **av);
void neighboors(map_t *map, int x, int y);
void set(map_t *map);
void solver(map_t *map);
float lenght(stack_t *c1, stack_t *c2);
void draw(map_t *map);
void sort_list_node(list_node li);
stack_t assign(char c, int x, int y);
void create_arrcell(map_t *map);
void swap(list_node la, list_node lb);
int check_node(list_node ptr);

#endif
