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
	char **instr;
	int i = 0;
	File *f = fopen(file, "r");

	if (!f)
	{
		fprintf(stderr, "Error: Can't open file %s", file);
		printf("\n");
		exit(EXIT_FAILURE);
	}
	instr = malloc(sizeof(char *) * 1024);
	if (!instr)
	{
		fprintf(stderr, "Error: malloc failed");
		printf("\n");
		exit(EXIT_FAILURE);
	}
	line_size = getline(&line, line_size, f);
	while (!feof(f))
	{
		instr[i] = line;
		i++;
		line_size = getline(&line, line_size, f);
	}
	fclose(f);
	return (instr);
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
 * @instr: instructions or opcodes to run
 */
void execute_opcode(char **instr)
{
	int i, j;
       	unsigned int line = 0, value;

	for (i = 0; instr[i]; i++)
	{
		line++;
		for (j = 0; j < 2; j++)
		{
			if (find(instr[i], inst[j].opcode) > 1)
			{
				fprintf(stderr, 
				"L%u: unknown instruction %s", 
				line, inst[j].opcode);
				printf("\n");
				exit (EXIT_FAILURE);
			}
			if (find(instr[i], inst[j].opcode) == 0)
				continue;
			else
			{
				inst[j].f(s, line);
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
	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file");
		printf("\n");
		exit(EXIT_FAILURE);
	}
	
	return (0);
}
