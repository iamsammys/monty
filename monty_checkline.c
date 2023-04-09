#include "monty.h"
#include <stdio.h>

/**
 * check_line - function to read lines in file.
 * @file: a file pointer
 *
 * Return: exit_status
 */
int check_line(FILE *file)
{
	char *line = NULL, **token, *delim = " \t\n\b";
	size_t size = 0;
	int line_num = 0, exit_status = EXIT_SUCCESS;
	stack_t *stack = NULL;

	while (getline(&line, &size, file) != -1)
	{
		line_num += 1;
		if (check_empty(line, delim) == 0)
			continue;

		token = line_parse(line);
		if (!token)
		{
			free(token);
			stack_free(&stack);
			free(line);
			return (EXIT_FAILURE);
		}

		if (strcmp(token[0], "push") == 0)
			exit_status = push(token, &stack, line_num);

		else
			exit_status = instruction(token, &stack, line_num);

		if (exit_status == EXIT_FAILURE)
			break;
		free(token);
	}

	if (exit_status == EXIT_FAILURE)
		free(token);
	stack_free(&stack);
	free(line);
	return (exit_status);
}

/**
 * check_empty - check if a read line is empty
 * @line: the line to check
 * @delim: the delimeter to compare with
 *
 * Return: 1 if not empty or 0 if empty
 */
int check_empty(char *line, char *delim)
{
	int i = 0, j = 0;

	if (!line || !delim)
		return (0);

	while (line[j])
	{
		i = 0;
		while (delim[i])
		{
			if (delim[i] == line[j])
				break;
			i++;
		}
		if (delim[i] == '\0')
			return (1);
		j++;
	}
	return (0);
}

/**
 * instruction - compares the bytecodes and
 * calls the corresponding function
 * @token: the bytecodes to compare
 * @stack: the stck to push to
 * @line_num: the current line number
 *
 * Return: the exit_status
 */

int instruction(char **token, stack_t **stack, int line_num)
{
	unsigned int line_number = line_num;
	int i = 0;

	instruction_t op_code[] = {
		{"pall", pall},
		{"pint", pint},
		{"null", NULL}
	};

	for (i = 0; i < 2; i++)
	{
		if (strcmp(op_code[i].opcode, token[0]) == 0)
		{
			op_code[i].f(stack, line_number);
			return (EXIT_SUCCESS);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, token[0]);
	return (EXIT_FAILURE);
}
