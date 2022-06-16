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
void opcode(stack_t **stack __attribute__((unused)), char *str, unsigned int line_cnt __attribute__((unused)))
{
	printf("%s", str);
	return;
}
