#include "monty.h"


/**
 * pchar - print values as chars if they are
 * @stack: linear structure we're working on
 * @line_number: #line in test file
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	/*printf("inside pchar ....\n");*/
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;

	/*printf("%d\n", value);*/
	if (isascii((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	fprintf(stderr, "%c\n", value);
}
