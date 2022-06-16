#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"


/**
 * opcode - function in charge of running builtins
 * @stack: stack given by main
 * @str: string to compare
 * @line_cnt: ammount of lines
 *
 * Return: nothing
 */
void opcode(stack_t **stack, char *str, unsigned int line_cnt)
{
	int i = 0;
	printf("%s", str);
	return;

	while (instructions[i].opcode)
	{
		if (strcmp(instructions[i].opcode, str) == 0)
		{
			instructions[i].f(stack, line_cnt);
			return; /* if we found a match, run the function */
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_cnt, str);
	status = EXIT_FAILURE;
}
