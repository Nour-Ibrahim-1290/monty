#include "monty.h"


/**
 * rotr - mod top of stack y second top stacks
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *count = *stack;

	int aux1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	while (count->next)
		count = count->next;

	aux1 = count->n;

	while (count->prev)
	{
		count = count->prev;
		count->next->n = count->n;
	}

	count->n = aux1;
}
