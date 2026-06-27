#include "apc.h"

int division(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **res_h, Dlist **res_t)
{
    Dlist *dividend_h = NULL, *dividend_t = NULL;
    Dlist *sub_h = NULL, *sub_t = NULL;
    Dlist *quot_h = NULL, *quot_t = NULL;
    Dlist *newquot_h = NULL, *newquot_t = NULL;
    Dlist *one_h = NULL, *one_t = NULL;

    if (is_zero(head2))
    {
        printf("divide by zero is undefined\n");
        return FAILURE;
    }
    delete_list(res_h, res_t);
    if (compare_list(head1, head2) < 0)
    {
        insert_first(res_h, res_t, 0);
        return SUCCESS;
    }
    copy_list(head1, &dividend_h, &dividend_t);
    insert_first(&quot_h, &quot_t, 0);
    insert_first(&one_h, &one_t, 1);

    while (compare_list(dividend_h, head2) >= 0)
    {
        subtraction(dividend_h, dividend_t, head2, tail2, &sub_h, &sub_t);
        delete_list(&dividend_h, &dividend_t);
        copy_list(sub_h, &dividend_h, &dividend_t);
        delete_list(&sub_h, &sub_t);

        addition(quot_h, quot_t, one_h, one_t, &newquot_h, &newquot_t);
        delete_list(&quot_h, &quot_t);
        copy_list(newquot_h, &quot_h, &quot_t);
        delete_list(&newquot_h, &newquot_t);
    }
    copy_list(quot_h, res_h, res_t);
    
    delete_list(&dividend_h, &dividend_t);
    delete_list(&quot_h, &quot_t);
    delete_list(&one_h, &one_t);
    delete_list(&sub_h, &sub_t);
    delete_list(&newquot_h, &newquot_t);
    return SUCCESS;
}