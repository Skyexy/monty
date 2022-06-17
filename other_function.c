#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

instruction_t instructions[] = {
	{"push", push},
	{NULL, NULL},
};

/**
 * opcode - function in charge of running builtins
 * @stack: stack given by main
 * @str: string to compare
 * @line_cnt: ammount of lines
 *
 * Return: nothing
 */
void opcode(stack_t **stack __attribute__((unused)), char *str, unsigned int line_cnt __attribute__((unused)))
{
	int i = 0;

	if (!strcmp(str, "stack"))
	{
		global.data_struct = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		global.data_struct = 0;
		return;
	}

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
void push(stack_t **stack, unsigned int line_cnt)
{
	char *n = argument;
	int num = atoi(n);

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}
	stack_t *new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		status = EXIT_FAILURE;
		return;
	}
	new->n = num;

	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
	return;
}
