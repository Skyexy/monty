#ifndef _MONTY_H_
#define _MONTY_H_

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#define INSTRUCTIONS { \
		{"push", push},\
		{"pall", pall},\
		{"pint", pint},\
		{"pop", pop},\
		{"swap", swap},\
		{"nop", nop},\
		{"div", _div},\
		{"mul", mul},\
		{"add", add},\
		{"sub", sub},\
		{"mod", mod},\
		{"pchar", pchar},\
		{"pstr", pstr},\
		{"rotl", rotl},\
		{"rotr", rotr},\
		{NULL, NULL} \
	}

typedef struct help
{
	int data_struct;
	char *argument;
} help;
help global;

void opcode(stack_t **stack, char *str, unsigned int line_cnt);
extern int status;
void push(stack_t **stack, unsigned int line_cnt);
int is_digit(char *string);
void pall(stack_t **stack, unsigned int line_cnt __attribute__((unused)));
size_t print_stack(const stack_t *stack);
void pint(stack_t **stack, unsigned int line_cnt);
void pop(stack_t **stack, unsigned int line_cnt);
void swap(stack_t **stack, unsigned int line_cnt);
void add(stack_t **stack, unsigned int line_cnt);
void nop(stack_t **stack, unsigned int line_cnt);
void sub(stack_t **stack, unsigned int line_cnt);
void _div(stack_t **stack, unsigned int line_cnt);
void mul(stack_t **stack, unsigned int line_cnt);
void pchar(stack_t **stack, unsigned int line_cnt);
void pstr(stack_t **stack, unsigned int line_cnt __attribute__((unused)));
void rotl(stack_t **stack, unsigned int line_count);
void rotr(stack_t **stack, unsigned int line_count);
stack_t *queue_node(stack_t **stack, const int n);
void mod(stack_t **stack, unsigned int line_cnt);
void free_stack(stack_t *stack);

#endif /* MONTY */
