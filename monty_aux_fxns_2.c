#include "monty.h"
/**
 * swap - swaps the first two values of the stack
 * @stack: the stack to pint the top
 * @line_number: the line of the instruction
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int value;

	if (!*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	temp = (*stack)->next;
	value = (*stack)->n;
	(*stack)->n = temp->n;
	temp->n = value;
	temp = NULL;
}
