#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"

/**
 * sub - computes the remainder of the division
 * @stack: stack given by main
 * @line_cnt: line counter
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_cnt)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}

	result = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, line_cnt);/*For top node*/
	(*stack)->n = result;
}
/**
 * _div - computes the remainder of the division
 * @stack: stack given by main
 * @line_cnt: line counter
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_cnt)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}

	result = ((*stack)->next->n) / ((*stack)->n);
	pop(stack, line_cnt);/*For top node*/
	(*stack)->n = result;
}
/**
 * mul - computes the remainder of the division
 * @stack: stack given by main
 * @line_cnt: line counter
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_cnt)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}

	result = ((*stack)->next->n) * ((*stack)->n);
	pop(stack, line_cnt);/*For top node*/
	(*stack)->n = result;
}

/**
 * mod - computes the remainder of the division
 * @stack: stack given by main
 * @line_cnt: line counter
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_cnt)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}

	result = ((*stack)->next->n) % ((*stack)->n);
	pop(stack, line_cnt);/*For top node*/
	(*stack)->n = result;
}

/**
 * mod - computes the remainder of the division
 * @stack: stack given by main
 * @line_cnt: line counter
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_cnt)
{
	char t;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}
	t = (char) (*stack)->n;
	if (isprint(t))
	{
		printf("%c\n", (*stack)->n);
	};
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}
}
