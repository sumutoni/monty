#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: stack of elements
 * @line_number: line where instruction was given
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *elm, *cur;
	(void) line_number;

	elm = malloc(sizeof(stack_t));
	if (!elm)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	elm->n = num;
	elm->next = NULL;
	if (!stack || !(*stack) || line_number == 1)
	{
		elm->prev = NULL;
		*stack = elm;
		return;
	}
	cur = *stack;
	while (cur->next)
		cur = cur->next;
	cur->next = elm;
	elm->prev = cur;
	*stack = elm;
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
		fprintf(stderr, "L%u: can't pint, stack empty", line_number);
		printf("\n");
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
		fprintf(stderr, "L%u: can't pop an empty stack",
				line_number);
		printf("\n");
		exit(EXIT_FAILURE);
	}
	cur = *stack;
	while (cur->next)
		cur = cur->next;
	cur->prev->next = NULL;
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
		fprintf(stderr, "L%u: can't swap, stack too short",
				line_number);
		printf("\n");
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
		fprintf(stderr, "L%u: can't add, stack too short",
				line_number);
		printf("\n");
		exit(EXIT_FAILURE);
	}
	cur = *stack;
	while (cur->next)
		cur = cur->next;
	result = cur->n + cur->prev->n;
	cur->prev->n = result;
	cur->prev->next = NULL;
	cur = NULL;
}
