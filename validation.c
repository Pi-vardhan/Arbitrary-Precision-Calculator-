#include "apc.h"

int validate_CLA(int argc, char *argv[])
{
    int i;

    if (argc != 4)
        return FAILURE;

    if (!(argv[2][0] == '+' || argv[2][0] == '-' || argv[2][0] == '*' || argv[2][0] == '/'))
        return FAILURE;

    for (i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
            return FAILURE;
    }

    for (i = 0; argv[3][i] != '\0'; i++)
    {
        if (!isdigit(argv[3][i]))
            return FAILURE;
    }
    return SUCCESS;
}