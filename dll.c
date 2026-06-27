#include "apc.h"

int insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));

    if (new == NULL)
        return FAILURE;

    new->data = data;
    new->prev = NULL;
    new->next = *head;

    if(*head)
        (*head)->prev = new;
    else
        *tail = new;

    *head = new;
    return SUCCESS;
}

int insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));

    if (new == NULL)
        return FAILURE;

    new->data = data;
    new->next = NULL;
    new->prev = *tail;

    if (*tail)
        (*tail)->next = new;
    else
        *head = new;

    *tail = new;
    return SUCCESS;
}

void delete_list(Dlist **head, Dlist **tail)
{
    Dlist *temp;

    while (*head)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    *tail = NULL;
}

void print_list(Dlist *head)
{
    if (head == NULL)
    {
        printf("0\n");
        return;
    }

    while (head)
    {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}

void convert_str_to_list(char *str, Dlist **head, Dlist **tail)
{
    while (*str)
    {
        insert_last(head, tail, *str - '0');
        str++;
    }
}