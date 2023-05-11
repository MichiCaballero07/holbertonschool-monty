#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

extern int error;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_tt;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_tt **stack, unsigned int line_number);
} instruction_t;


void _push(stack_tt **stack, unsigned int line_number);
void _pall(stack_tt **stack, unsigned int line_number);
void _pint(stack_tt **stack, unsigned int line_number);
void _pop(stack_tt **stack, unsigned int line_number);
void _swap(stack_tt **stack, unsigned int line_number);
void _add(stack_tt **stack, unsigned int line_numer);
void _nop(stack_tt **stack, unsigned int line_number);

void check_opcode(char *op, stack_tt **stack, unsigned int line_number);
void free_all(stack_tt *stack, FILE *fd);

stack_tt *add_node(stack_tt **stack, int n);
int check_digit(char *arg);
int _isdigit(int c);

#endif