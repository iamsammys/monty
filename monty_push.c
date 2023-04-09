#include "monty.h"

/**
 * push - a function that pushes a value to the stack
 * @token: the value to push
 * @stack: the stack
 * @line_num: the line number from bytecode
 *
 * Return: EXIT_STATUS
 */

int push(char **token, stack_t **stack, int line_num)
{
	int i;
	stack_t *new_node;

	if (!token[1])
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		return (EXIT_FAILURE);
	}

	i = 0;
	while (token[1][i])
	{
		if (token[1][i] == '-')
		{
			i++;
			continue;
		}

		if (token[1][i] < '0' || token[1][i] > '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			return (EXIT_FAILURE);
		}
		i++;
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}
	new_node->n = atoi(token[1]);
	new_node->prev = NULL;
	if ((*stack) != NULL)
		(*stack)->prev = new_node;
	new_node->next = *stack;
	*stack = new_node;
	return (EXIT_SUCCESS);
}
