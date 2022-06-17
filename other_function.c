#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"

instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
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
		return;
	}
	if (!strcmp(str, "queue"))
	{
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
	stack_t *new = malloc(sizeof(stack_t));

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_cnt);
		free(new);
		status = EXIT_FAILURE;
		return;
	}
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

/**
 * pall - prints the stack
 * @stack: stack given by main
 * @line_cnt: ammount of lines
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
	print_stack(*stack);
}

/**
 * print_stack - prints the contents of a stack_t stack
 * @stack: stack head
 *
 * Return: number of elements of the list
 */
size_t print_stack(const stack_t *stack)
{
	size_t c = 0;
	
	while (stack)
	{
		printf("%d\n", (stack)->n);
		stack = stack->next;
		c++;
	}
	return(c);
}

/**
 * is_digit - checks if a string is a digit
 * @string: string to check
 *
 * Return: 1 if success, 0 if not
 */
int is_digit(char *string)
{
	if (!string || *string == '\0')
		return (0);
	if (*string == '-')
		string++;
	while (*string)
	{
		if (isdigit(*string) == 0)
			return (0);
		string++;
	}
	return (1);
}
