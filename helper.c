#include "apc.h"

int count_nodes(Dlist *head)
{
    int count = 0;

    while(head)
    {
        count++;
        head = head->next;
    }
    return count;
}

int compare_list(Dlist *head1, Dlist *head2)
{
    int len1 = count_nodes(head1);
    int len2 = count_nodes(head2);

    if(len1 > len2)
        return 1;

    if(len1 < len2)
        return -1;

    while(head1 && head2)
    {
        if(head1->data > head2->data)
            return 1;

        if(head1->data < head2->data)
            return -1;

        head1 = head1->next;
        head2 = head2->next;
    }
    return 0;
}

int copy_list(Dlist *src, Dlist **dest_h, Dlist **dest_t)
{
    delete_list(dest_h, dest_t);

    while(src)
    {
        insert_last(dest_h, dest_t, src->data);
        src = src->next;
    }
    return SUCCESS;
}

void remove_leading_zeros(Dlist **head, Dlist **tail)
{
    while(*head && (*head)->data == 0 && (*head)->next)
    {
        Dlist *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }

    if(*head == NULL)
        *tail = NULL;
}

int is_zero(Dlist *head)
{
    while(head)
    {
        if(head->data != 0)
            return 0;
        head = head->next;
    }

    return 1;
}