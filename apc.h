#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Dlist;

//validation 
int validate_CLA(int argc, char *argv[]);

//DLL Operations 
int insert_first(Dlist **head, Dlist **tail, int data);
int insert_last(Dlist **head, Dlist **tail, int data);
void delete_list(Dlist **head, Dlist **tail);
void print_list(Dlist *head);

//conversion 
void convert_str_to_list(char *str, Dlist **head, Dlist **tail);

//Helper functions 
int compare_list(Dlist *head1, Dlist *head2);
int count_nodes(Dlist *head);
int copy_list(Dlist *src, Dlist **dest_h, Dlist **dest_t);
void remove_leading_zeros(Dlist **head, Dlist **tail);
int is_zero(Dlist *head);

extern int subtraction_sign;

//Arithmetic operations 
int addition(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **res_h, Dlist **res_t);
int subtraction(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **res_h, Dlist **res_t);
int multiplication(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **res_h, Dlist **res_t);
int division(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **res_h, Dlist **res_t);

#endif