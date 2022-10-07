#include "monty.h"

/**
 * count_lines - counts lines in a file
 * @file: file
 *
 * Return: number of lines
 */
int count_lines(char *file)
{
	int lines = 0;
	char c;
	FILE *f = fopen(file, "r");

	if (!f)
	{
		free_struct(stack);
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	for (c = getc(f); c != EOF; c = getc(f))
	{
		if (c == '\n')
			lines++;
	}
	fclose(f);
	return (lines);
}
/**
 * read_file - reads the file passed to the program
 * @file: file to read from
 *
 * Return: pointer containing all instructions
 */
char **read_file(char *file)
{
	char *line = NULL;
	size_t line_size = 0;
	char **ins;
	int i = 0;
	FILE *f = fopen(file, "r");

	if (!f)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	size = count_lines(file);
	ins = malloc(sizeof(char *) * size);
	if (!ins)
	{
		free_struct(stack);
		free(ins);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	line_size = getline(&line, &line_size, f);
	while (!feof(f))
	{
		ins[i] = malloc(sizeof(char) * line_size + 1);
		strcpy(ins[i], line);
		i++;
		line_size = getline(&line, &line_size, f);
	}
	free(line);
	fclose(f);
	return (ins);
}
/**
 * find - finds an opcode in a string
 * @str: string to search in
 * @op: opcode to find
 *
 * Return: the number of times the opcode occurs in the string
 */
int find(char *str, char *op)
{
	int count = 0;
	char *token;

	token = strstr(str, op);
	if (token)
	{
		count++;
	}
	return (count);
}
/**
 * execute_opcode - runs the opcodes found in the monty file
 * @ins: instructions or opcodes to run
 * @inst: array of opcodes and their functions
 * @s: stack of elements
 */
void execute_opcode(char **ins, instruction_t inst[], stack_t **s)
{
	int i, j, val;
	unsigned int line = 0;
	char *copy;

	for (i = 0; i < size; i++)
	{
		copy = malloc(sizeof(char) * 1024);
		if (!copy)
		{
			free_2D(ins);
			free_struct(*s);
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		line++;
		strcpy(copy, ins[i]);
		for (j = 0; j < 7; j++)
		{
			val = find(copy, inst[j].opcode);
			if (val > 1)
			{
				fprintf(stderr,
				"L%u: unknown instruction %s\n",
				line, inst[j].opcode);
				exit(EXIT_FAILURE);
			}
			if (val == 0)
				continue;
			if (val == 1)
			{
				if (strcmp(inst[j].opcode, "push") == 0)
					extract_num(ins[i], line);
				free(copy);
				inst[j].f(s, line);
				break;
			}
		}
	}
}
/**
 * main - main function of the program
 * @argc: number of arguments passed to the function
 * @argv: pointer to the arguments passed
 *
 * Return: 0 for success
 */
int main(int argc, char *argv[])
{
	instruction_t inst[] = {{"push", push}, {"pall", pall}, {"pint", pint},
				{"pop", pop}, {"swap", swap}, {"add", add},
				{"nop", nop}};

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	stack = malloc(sizeof(stack_t));
	if (!stack)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	stack = NULL;
	instr = read_file(argv[1]);
	execute_opcode(instr, inst, &stack);
	free_struct(stack);
	free_2D(instr);
	return (0);
}
