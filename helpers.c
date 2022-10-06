#include "monty.h"

/**
 * extract_num - extracts number from string
 * @str: string to extract from
 * @line_number: line where instruction was given
 */
void extract_num(char *str, unsigned int line_number)
{
	int neg = 1;

	num = 0;
	while (*str && (*str < '0' || *str > '9'))
	{
		if (*str == '-')
			neg = -1;
		++str;
	}
	if (*str == '\0')
	{
		fprintf(stderr, "L%u: usage: push integer", line_number);
		printf("\n");
		exit(EXIT_FAILURE);
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - 48);
		++str;
	}
	if (*str != ' ' || *str != '\t' || *str == '\0' || *str != '\n')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = num * neg;
}
/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack
 * @stack: stack of elements
 * @line_number: line where instruction was given
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *cur;
	(void) line_number;

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
 * nop - doesn't do anything
 * @stack: stack of elements
 * @line_number: line where instruction was given
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
