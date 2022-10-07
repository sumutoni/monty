#include "monty.h"

/**
 * extract_num - extracts number from string
 * @str: string to extract from
 * @line_number: line where instruction was given
 */
void extract_num(char *str, unsigned int line_number)
{
	int neg = 1, i = 0;

	num = 0;
	while (str[i] && (str[i] < '0' || str[i] > '9'))
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	if (str[i] == '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	if (str[i] != ' ' && str[i] != '\t' && str[i] != '\0' && str[i] != '\n'
			&& str[i] != '$')
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
	while (cur->next)
		cur = cur->next;
	while (cur)
	{
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
