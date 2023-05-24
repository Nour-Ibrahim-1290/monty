#include "monty.h"


/**
 * main - check point
 * Description: read monty file and execute the opcodes
 * @argc: # arguments
 * @argv: array of the arguments
 *
 * Return: int success status
 */

int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	stack_t *stack = malloc(sizeof(stack_t));
	char *line = NULL, *opcode = NULL;
	size_t line_length = 0;
	unsigned int line_number = 1;
	int i;

	/* Create an instruction table */
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	/* Check if the user has provided a file name */
	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Open the file */
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Create a stack */
	if (stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Initialize the stack ???? do i really i need it?*/
	stack->n = 0;
	stack->prev = NULL;
	stack->next = NULL;

	/* Read the bytecodes from the file */
	while (getline(&line, &line_length, file) != -1)
	{
		/* Parse the bytecode */
		opcode = strtok(line, " \n");

		/* Execute the opcode */
		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, line_number);
				break;
			}
		}

		if (instructions[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}

	/* Free the memory allocated for the line buffer */
	free(line);

	/* Close the file */
	fclose(file);

	return (0);
}
