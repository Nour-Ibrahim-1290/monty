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

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;

	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar(value);
}
