#include "monty.h"



/**
 *pint - function that prints the number in the stack
 *
 *@stack: pointer to linked list stack
 *
 *@line_number: line number opcode occurs
 *
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *loop;

	loop = *stack;

	if (loop == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", loop->n);
}


