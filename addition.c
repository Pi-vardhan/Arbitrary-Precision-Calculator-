#include "apc.h"

int addition(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **res_h, Dlist **res_t)
{
    int carry = 0;

    delete_list(res_h, res_t);
    while(tail1 || tail2 || carry)
    {
        int sum = carry;

        if(tail1)
        {
            sum += tail1->data;
            tail1 = tail1->prev;
        }

        if(tail2)
        {
            sum += tail2->data;
            tail2 = tail2->prev;
        }

        insert_first(res_h, res_t, sum % 10);
        carry = sum / 10;
    }
    remove_leading_zeros(res_h, res_t);
    return SUCCESS;
}