#include "monty.h"

/**
 * main - main monty program to handle the bytecode files
 * @argc: Argument
 * @argv: Argument
 * Return: EXIT_FAILURE, EXIT_SUCCESS.
 */
int main(int argc, char **argv)
{
        FILE *fd;
        stack_tt *stack = NULL;
        unsigned int line_number = 0;
        char str[1024];
        char *tok = NULL;
        size_t n = 1024;

        if (argc != 2)
        {
                fprintf(stderr, "USAGE: monty file\n");
                exit(EXIT_FAILURE);
        }

        fd = fopen(argv[1], "r");
        if (fd == NULL)
        {
                fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
                exit(EXIT_FAILURE);
        }
        while (fgets(str, n, fd) != NULL && error != 1)
        {
                line_number++;
                tok = strtok(str, "\n\t ");
                if (tok != NULL)
                {
                        check_opcode(tok, &stack, line_number);
                }
        }
        free_all(stack, fd);

        if (error == 1)
                exit(EXIT_FAILURE);
        return (EXIT_SUCCESS);
}