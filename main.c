#include "apc.h"

int main(int argc, char *argv[])
{
    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *res_h = NULL, *res_t = NULL;

    if (validate_CLA(argc, argv) == FAILURE)
    {
        printf("Usage: ./apc <num1> <operator> <num2>\n");
        return FAILURE;
    }

    convert_str_to_list(argv[1], &head1, &tail1);
    convert_str_to_list(argv[3], &head2, &tail2);

    switch (argv[2][0])
    {
        case '+':
            addition(head1, tail1, head2, tail2, &res_h, &res_t);
            break;

        case '-':
            subtraction(head1, tail1, head2, tail2, &res_h, &res_t);
            break;

        case '*':
            multiplication(head1, tail1, head2, tail2, &res_h, &res_t);
            break;

        case '/':
            if (division(head1, tail1, head2, tail2, &res_h, &res_t) == FAILURE)
            {
                delete_list(&head1, &tail1);
                delete_list(&head2, &tail2);
                return FAILURE;
            }
            break;

        default:
            printf("Invalid Operator\n");
            delete_list(&head1, &tail1);
            delete_list(&head2, &tail2);
            return FAILURE;
    }

    printf("Result : ");

    if (argv[2][0] == '-' && subtraction_sign)
        printf("-");

    print_list(res_h);

    delete_list(&head1, &tail1);
    delete_list(&head2, &tail2);
    delete_list(&res_h, &res_t);

    return SUCCESS;
}