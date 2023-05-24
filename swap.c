#include "monty.h"


/**
 *swap - function that switches places of stack
 *
 *@stack: pointer to linked list stack
 *
 *@line_number: number of line opcode occurs on
 *
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *count;

	int switched;

	count = *stack;

	if (count == NULL || count->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		error_exit(stack);
	}

	switched = count->n;
	count->n = count->next->n;
	count->next->n = switched;
}
