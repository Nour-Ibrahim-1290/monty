#include "monty.h"

/**
 * mul - multiply the top 2 elemnts in 2nd element and pop 1st
 * @stack: linear node structure
 * @line_number: number of line in monty file
 *
 * Return: void
 */

void mul(stack_t **stack, unsigned int line_number)
{
	int sum;

	/* Check if the stack contains less than two elements.*/
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Get the value of the 2nd top element*/
	sum = (*stack)->next->n;

	/* Add the value to the top element.*/
	sum *= (*stack)->n;

	/* Remove the top element from the stack.*/
	pop(stack, line_number);

	/*update the value of the new top element*/
	(*stack)->n = sum;
}
