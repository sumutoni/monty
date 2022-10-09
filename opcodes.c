#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: stack of elements
 * @line_number: line where instruction was given
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *cur;
	(void) line_number;

	if (!stack || !(*stack))
	{
		*stack = malloc(sizeof(stack_t));
		if (!(*stack))
		{
			free_2D(instr);
			free_struct(*stack);
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		(*stack)->n = num;
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
		return;
	}
	cur = *stack;
	while (cur->next)
		cur = cur->next;
	cur->next = malloc(sizeof(stack_t));
	if (!cur->next)
	{
		free_2D(instr);
		free_struct(*stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	cur->next->n = num;
	cur->next->prev = cur;
	cur->next->next = NULL;
	*stack = cur->next;
}
/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @stack: stack of elements
 * @line_number: line where instruction was given
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *cur;

	if (!stack || !(*stack))
	{
		free_2D(instr);
		free_struct(*stack);
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	cur = *stack;
	if (cur->next != NULL)
	{
		while (cur->next)
		{
			cur = cur->next;
		}
	}
	printf("%d\n", cur->n);
}
/**
 * pop - removes the top element of the stack
 * @stack: stack of elements
 * @line_number: line where instruction was given
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *cur;

	if (!stack || !(*stack))
	{
		free_2D(instr);
		free_struct(*stack);
		fprintf(stderr, "L%u: can't pop an empty stack\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	cur = *stack;
	while (cur->next)
		cur = cur->next;
	cur->prev->next = NULL;
	*stack = cur->prev;
	free(cur);
	cur = NULL;
}
/**
 * swap - swaps the top two elements of the stack
 * @stack: stack of elements
 * @line_number: line where instruction was given
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *cur;
	int temp;

	if (!stack || !(*stack) || (!(*stack)->next && !(*stack)->prev))
	{
		free_struct(*stack);
		free_2D(instr);
		fprintf(stderr, "L%u: can't swap, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	cur = *stack;
	while (cur->next)
		cur = cur->next;
	temp = cur->n;
	cur->n = cur->prev->n;
	cur->prev->n = temp;
}
/**
 * add - adds the top two elements of the stack.
 * @stack: stack of elements
 * @line_number: line where instruction was given
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *cur;
	int result;

	if (!stack || !(*stack) || (!(*stack)->next && !(*stack)->prev))
	{
		free_struct(*stack);
		free_2D(instr);
		fprintf(stderr, "L%u: can't add, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	cur = *stack;
	while (cur->next)
		cur = cur->next;
	result = cur->n + cur->prev->n;
	cur->prev->n = result;
	cur->prev->next = NULL;
	*stack = cur->prev;
	free(cur);
	cur = NULL;
}
