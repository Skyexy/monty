#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

/**
 * error_usage - prints usage message and exits
 *
 * Return: nothing
 */
void error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * file_error - prints file error message and exits
 * @argv: argv given by manin
 *
 * Return: nothing
 */
void file_error(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}

/**
 * main - entry point
 * @argv: list of arguments passed to our program
 * @argc: ammount of args
 *
 * Return: nothing
 */
int main(int argc, char **argv)
{
	FILE *file;
	char buffer[1024];
	char *str = NULL;
	int n = 1024;
	stack_t *stack = NULL;
	unsigned int line_count = 1;
	int status = 0;
	char *argument;
	int que = 1;

	if (argc != 2)
		error_usage();

	file = fopen(argv[1], "r");

	if (!file)
		file_error(argv[1]);

	while (fgets(buffer, n, file) != NULL)
	{
		if (status)
			break;
		if (*buffer == '\n')
		{
			line_count++;
			continue;
		}
		str = strtok(buffer, " \t\n");
		if (!str || *str == '#')
		{
			line_count++;
			continue;
		}
		argument = strtok(NULL, " \t\n");
		opcode(&stack, str, line_count);
		line_count++;
	}
	free_stack(stack);
	fclose(file);
	exit(status);
}
