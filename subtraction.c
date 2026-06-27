#include "apc.h"

int subtraction_sign = 0;

int subtraction(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **res_h, Dlist **res_t)
{
    int cmp;
    int borrow = 0;

    delete_list(res_h, res_t);
    subtraction_sign = 0;
    cmp = compare_list(head1, head2);

    if(cmp == 0)
    {
        insert_first(res_h, res_t, 0);
        return SUCCESS;
    }

    if(cmp < 0)
    {
        subtraction_sign = 1;
        Dlist *tmp;

        tmp = head1;
        head1 = head2;
        head2 = tmp;

        tmp = tail1;
        tail1 = tail2;
        tail2 = tmp;
    }

    while(tail1)
    {
        int d1 = tail1->data - borrow;
        int d2 = 0;

        if(tail2)
        {
            d2 = tail2->data;
            tail2 = tail2->prev;
        }

        if(d1 < d2)
        {
            d1 += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        insert_first(res_h, res_t, d1 - d2);
        tail1 = tail1->prev;
    }
    remove_leading_zeros(res_h, res_t);
    return SUCCESS;
}