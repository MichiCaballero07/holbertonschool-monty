#include "monty.h"

/**
 *_push - push an integer onto the stack
 *@stack: double pointer of stack
 *@line_number: line number of file we process
 *
 */

void _push(stack_t **stack, unsigned int line_number)
{
	int data;
	char *arg;

	arg = strtok(NULL, "\n\t ");
	if (arg == NULL || check_digit(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	data = atoi(arg);
	if (add_node(stack, data) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * _pall - prints all value on stack from top to down
 * @stack: double pointer of stack
 * @line_number: line number we are executing
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *mover;

	(void)line_number;

	mover = *stack;
	while (mover != NULL)
	{
		printf("%d\n", mover->n);
		mover = mover->next;
		if (mover == *stack)
		{
			return;
		}
	}
}

/**
 * _pint - print the last element of the stack
 * @stack: double pointer of stack
 * @line_number: number of the line in case of error
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * _pop - Removes the top element in stack
 * @stack: double pointer of stack
 * @line_number: number of the line in case of error
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}