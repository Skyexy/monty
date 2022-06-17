#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

int status = 0;
char *argument;

int main(int argc, char **argv)
{
	FILE *file;
	char buffer[1024];
	char *str = NULL;
	int n = 1024;
	stack_t *stack = NULL;
	unsigned int line_count = 1;
	
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, n, file) != NULL)
	{
		if (status)
		{
			break;
		}
		if (*buffer == '\n')
		{
			line_count++;
			continue;
		}
		str = strtok(buffer, " \t\n");
		argument = strtok(NULL, " \t\n");
		opcode(&stack, str, line_count);
		line_count++;
	}
	exit(status);
}
