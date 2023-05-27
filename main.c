#include "monty.h"


void execute(char *opcode, stack_t *stack, unsigned int line_number);
void check(int argc, char *argv[], FILE *file);
void free_stack(stack_t *head);
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
	stack_t *stack = NULL;
	char *line = NULL, *opcode = NULL; /*strip_line = NULL;*/
	size_t line_length = 0;
	unsigned int line_number = 1;
	int i;
	instruction_t instructions[] = {
		{"push", push}, {"add", add}, {"sub", sub},
		{"pall", pall}, {"pop", pop}, {"nop", nop},
		{"div", divide}, {"swap", swap}, {"pint", pint},
		{"mul", mul}, {"pstr", pstr}, {"rotr", rotr},
		{"mod", mod}, {"pchar", pchar}, {NULL, NULL}
	};

	/* printf("Before check ....\n"); */
	/*Check if the user provided a file name*/
	check(argc, argv, file);

	/* printf("After check ...\n"); */
	while (getline(&line, &line_length, file) != -1 && !feof(file))
	{/* Read the bytecodes from the file*/
		/*printf("In WHILE line is %s\n", line);*/
		opcode = strtok(line, " \n");
		if (opcode == NULL || strncmp(opcode, "#", 1) == 0)
		{
			line_number++;
			continue;
		}
		/*printf("opcode = %s\n", opcode);*/
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
	free(line); /* Free the memory allocated for the line buffer */
	free_stack(stack);
	fclose(file); /* Close the file */
	return (0);
}


/**
 * free_stack - free the memory that's reserved for stck
 * @head: atck structure
 *
 * Return: void
 */

void free_stack(stack_t *head)
{
	stack_t *next;

	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
}

/**
 * check - perform checks
 * @argc: number of args in main
 * @argv: array of args
 * @file: monty file pointer, which we read opcodes from
 *
 * Return: void
 */
void check(int argc, char *argv[], FILE *file)
{
	if (argc != 2) /* Check if the user provided a file name */
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* printf("There're al least 2 args\n"); */
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

}

/**
 * execute - function to perform the loop (testing)
 * @opcode: to perform
 * @stack: to work in
 * @line_number: in the monty file
 *
 * return: void
 */

void execute(char *opcode, stack_t *stack, unsigned int line_number)
{
	int i;
	instruction_t instructions[] = {
		{"push", push}, {"pstr", pstr}, {"rotr", rotr},
		{"pall", pall}, {"div", divide}, {"nop", nop},
		{"pop", pop}, {"swap", swap}, {"pint", pint},
		{"mul", mul}, {"sub", sub}, {"add", add}, {"mod", mod},
		{NULL, NULL}
	};

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
}
