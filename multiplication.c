#include "apc.h"

int multiplication(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **res_h, Dlist **res_t)
{
    Dlist *temp1_h = NULL, *temp1_t = NULL;
    Dlist *temp2_h = NULL, *temp2_t = NULL;
    Dlist *final_h = NULL, *final_t = NULL;

    int shift = 0;
    delete_list(res_h, res_t);

    while(tail2)
    {
        int digit = tail2->data;
        int carry = 0;
        Dlist *ptr = tail1;

        delete_list(&temp2_h, &temp2_t);
        while(ptr)
        {
            int product = (ptr->data * digit) + carry;
            insert_first(&temp2_h, &temp2_t, product % 10);
            carry = product / 10;
            ptr = ptr->prev;
        }

        if(carry)
            insert_first(&temp2_h, &temp2_t, carry);

        for(int i = 0; i < shift; i++)
            insert_last(&temp2_h, &temp2_t, 0);

        if(temp1_h == NULL)
        {
            copy_list(temp2_h, &temp1_h, &temp1_t);
        }
        else
        {
            addition(temp1_h, temp1_t, temp2_h, temp2_t, &final_h, &final_t);
            delete_list(&temp1_h, &temp1_t);
            copy_list(final_h, &temp1_h, &temp1_t);
            delete_list(&final_h, &final_t);
        }
        shift++;
        tail2 = tail2->prev;
    }

    copy_list(temp1_h, res_h, res_t);
    remove_leading_zeros(res_h, res_t);
    delete_list(&temp1_h, &temp1_t);
    delete_list(&temp2_h, &temp2_t);
    delete_list(&final_h, &final_t);
    return SUCCESS;
}