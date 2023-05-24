#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

/*
 * push - push a node at the beginning of the structure
 * @stack: a stack struct
 * @line_number: num of line on monty file where
 * the opcode is written
 *
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number) {
  int value;
  char *argument;
  stack_t *new_node = malloc(sizeof(stack_t));

  argument = strtok(NULL, " ");
  if (argument == NULL) {
    fprintf(stderr, "L%d: usage: push integer\n", line_number);
    exit(EXIT_FAILURE);
  }

  value = atoi(argument);
  if (value < 0) {
    fprintf(stderr, "L%d: value must be non-negative\n", line_number);
    exit(EXIT_FAILURE);
  }

  /* Push the value onto the stack.*/
  new_node->n = value;
  new_node->prev = NULL;
  new_node->next = *stack;
  *stack = new_node;

  /* printf("%d\n", value);*/
}
