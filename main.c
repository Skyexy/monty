#include <stdlib.h>
#include <stdio.h>
#include <string.h>

status = 0;

int main(int argc, char **argv)
{
	FILE *file;
	char *buffer = NULL;
	char *str = NULL;
	stack_t stack = NULL;
	unsigned int line_count = 1;
	
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, 1024, file) != NULL)
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
		opcode(&stack, str, line_count);
		line_count++;
	}
	free(buffer);
	free_stack(stack);
	fclose(file);
	exit(status);
}
