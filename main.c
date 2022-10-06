#include "monty.h"

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
		fprintf(stderr, "Error: Can't open file %s", file);
		printf("\n");
		exit(EXIT_FAILURE);
	}
	ins = malloc(sizeof(char *) * 1024);
	if (!ins)
	{
		fprintf(stderr, "Error: malloc failed");
		printf("\n");
		exit(EXIT_FAILURE);
	}
	line_size = getline(&line, &line_size, f);
	while (!feof(f))
	{
		ins[i] = line;
		i++;
		line_size = getline(&line, &line_size, f);
	}
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

	token = strtok(str, op);
	while (token)
	{
		count++;
		token = strtok(NULL, op);
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
	int i, j;
	unsigned int line = 0;
	char *copy;

	copy = malloc(sizeof(char) * 1024);
	if (!copy)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; ins[i]; i++)
	{
		line++;
		strcpy(copy, ins[i]);
		for (j = 0; j < 7; j++)
		{
			if (find(copy, inst[j].opcode) > 1)
			{
				fprintf(stderr,
				"L%u: unknown instruction %s",
				line, inst[j].opcode);
				printf("\n");
				exit(EXIT_FAILURE);
			}
			if (find(copy, inst[j].opcode) == 0)
				continue;
			else
			{
				if (strcmp(inst[j].opcode, "push") == 0)
					extract_num(ins[i], line);
				inst[j].f(s, line);
				continue;
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
	stack_t *stack;
	instruction_t inst[] = {{"push", push}, {"pall", pall}, {"pint", pint},
				{"pop", pop}, {"swap", swap}, {"add", add},
				{"nop", nop}};

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file");
		printf("\n");
		exit(EXIT_FAILURE);
	}
	stack = malloc(sizeof(stack_t));
	if (!stack)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	instr = read_file(argv[1]);
	execute_opcode(instr, inst, &stack);
	free(stack);
	free(instr);
	return (0);
}
