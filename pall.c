#include "monty.h"

/**
 *pall - function that prints all functions
 *
 *@stack: pointer representation of the linked list
 *
 *@line_number: stands for representation of the stack
 *
 */

void pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *count;

	count = *stack;

	while (count != NULL)
	{
		printf("%d\n", count->n);
		count = count->next;
	}
}
