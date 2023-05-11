#include "monty.h"

/**
 * free_all - function to free and leave proper
 * @stack: pointer to head of stack
 * @fd: pointer to file opened
 */

void free_all(stack_tt *stack, FILE *fd)
{
	stack_tt *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	fclose(fd);
}

/**
 * add_node - add a newnode at beginning of our
 * linked-listed behavior stack
 * @stack: double pointer to head of stack
 * @n: new data to fill in new node
 * Return: pointer to new node
 */
stack_tt *add_node(stack_tt **stack, int n)
{
	stack_tt *new;

	new = malloc(sizeof(stack_tt));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = *stack;
	new->prev = NULL;

	if (*stack)
		(*stack)->prev = new;

	*stack = new;
	return (new);
}

/**
 * check_digit - check if the string contains only digits
 * @arg: pointer on argument to check
 * Return: 0 if only digits are found, 1 otherwise
 */

int check_digit(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (_isdigit(arg[i]) == 0)
			return (1);
	}
	return (0);
}

/**
* _isdigit -  prints if the character is a digit.
* @c: character to check.
* Return: 0 if exited correctly, non-zero otherwise.
*/

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}