#include "monty.h"

/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack
 * @stack: stack of elements
 * @line_number: line where instruction was given
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *cur;

	if (!stack || !(*stack))
		return;
	cur = *stack;
	while (cur)
	{
		if (cur->next != NULL)
		{
			cur = cur->next;
			continue;
		}
		printf("%d\n", cur->n);
		cur = cur->prev;
	}
}
/**
 * push - pushes an element to the stack.
 * @stack: stack of elements
 * @line_number: line where instruction was given
 */
void push(stack_t **stack, unsigned int line_number)
{

}
/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @stack: stack of elements
 * @line_number: line where instruction was given
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *cur;

	if (!stack ||!(*stack))
	{
		fprintf(stderr, "L%u: can't pint, stack empty", line_number);
		printf("\n");
		exit (EXIT_FAILURE);
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
 * nop - doesn't do anything
 * @stack: stack of elements
 * @line_number: line where instruction was given
 */
void nop(stack_t **stack, unsigned int line_number)
{
	return;
}
