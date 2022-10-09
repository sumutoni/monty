#include "monty.h"

void free_struct(stack_t *sct);
void free_instr(char **ar);
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
		free_struct(stack);
		free_2D(instr);
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
		free_struct(stack);
		free_2D(instr);
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
	(void) line_number;
	(void) stack;
}
/**
 * free_struct - frees a struct
 * @sct: struct to free
 */
void free_struct(stack_t *sct)
{
	stack_t *tmp;

	while (sct)
	{
		tmp = sct;
		sct = sct->prev;
		free(tmp);
		tmp = NULL;
	}
}
/**
 * free_2D - frees 2D array
 * @ar: array to free
 */
void free_2D(char **ar)
{
	int i;

	for (i = 0; i < size; i++)
	{
		free(ar[i]);
		ar[i] = NULL;
	}
	free(ar);
	ar = NULL;
}
