#include "monty.h"

/**
 * line_parse - tokenizes a string
 * @line: the line of string to be tokenised
 *
 * Return: array of pointers to string
 */

char **line_parse(char *line)
{
	char **token_arr = NULL, *tokens = NULL;
	int i, token_count;

	if (!line || !DELIM)
		return (NULL);

	token_arr = malloc(sizeof(char *) * strlen(line));
	if (!token_arr)
	{
		free(token_arr);
		return (NULL);
	}

	tokens = strtok(line, DELIM);
	if (!tokens)
	{
		free(token_arr);
		return (NULL);
	}

	i = 0;
	token_count = MAX_TOKENS;
	while (tokens && token_count)
	{
		*(token_arr + i) = tokens;
		i++;
		tokens = strtok(NULL, DELIM);
		token_count--;
	}
	*(token_arr + i) = NULL;

	return (token_arr);
}

/**
 * stack_free - frees the stack from memory
 * @stack: a pointer to the head of the node
 *
 * return: void
 */

void stack_free(stack_t **stack)
{
	stack_t *temp;

	if (!(*stack))
		return;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

/**
 * pall - prints the stack to the stdout
 * @stack: the stack to print
 * @line_number: the line number of the command
 *
 * return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	if (*stack)
	{
		head = *stack;
		while (head)
		{
			fprintf(stdout, "%d\n", head->n);
			head = head->next;
		}
	}
}
