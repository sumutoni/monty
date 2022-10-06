#include "monty.h"

/**
 * extract_num - extracts number from string
 * @str: string to extract from
 * @line_number: line where instruction was given
 */
void extract_num(char *str, unsigned int line_number)
{
	char *s;
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
		num = (num * 10) + atoi(*str);
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
 * nop - doesn't do anything
 * @stack: stack of elements
 * @line_number: line where instruction was given
 */
void nop(stack_t **stack, unsigned int line_number)
{
}
