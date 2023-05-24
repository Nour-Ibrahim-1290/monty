#include "monty.h"

/**
 * main - entry point
 *
 * Return: exit status
 */

int main(int argc, char *argv[]) {
	FILE *file = fopen(argv[1], "r");
	struct instruction_s instructions[] = {
		{"push", push},{NULL, NULL}};
	char *line = NULL;
	size_t line_length = 0;
	unsigned int line_number = 1;
	int opcode, i;
	char *argument;
	void (*f)(stack_t **stack, unsigned int line_number) = NULL;
  
	if (argc != 2) {
		fprintf(stderr, "Usage: monty bytecodes/file.m\n");
		exit(EXIT_FAILURE);
	}

	/* Open the bytecodes file.*/
	if (file == NULL) {
		fprintf(stderr, "Could not open bytecodes file: %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Read the bytecodes from the file */
	while (getline(&line, &line_length, file) != -1)
	{
		/* Parse the bytecode.*/
		sscanf(line, "%d %s", &opcode, argument);

		/* Execute the opcode.*/
		for (i = 0; i < sizeof(instructions) / sizeof(instructions[0]); i++)
		{
			if (strcmp(instructions[i].opcode, argument) == 0)
			{
				f = instructions[i].f;
				break;
			}
		}
		if (f == NULL)
		{
			fprintf(stderr, "Unknown opcode: %d\n", opcode);
			exit(EXIT_FAILURE);
		}

		f(&stack_t, line_number);

		line_number++;
	}

	/* Free the memory allocated for the line buffer.*/
	free(line);

	/* Close the bytecodes file.*/
	fclose(file);

	return 0;
}
