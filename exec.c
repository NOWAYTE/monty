#include "monty.h"

/**
 * funct - pointers to functions
 * @token: opcode
 * Return: fuction
 */

void (*funct(char *token))(stack_t **stack, unsigned int line_number)
{
	instruction_t opco[] = {
		{"push", s_push},
		{"pall", s_pall},
		{NULL, NULL}};
	int i = 0;
	int op;

	while (i < 19)
	{
		op = strcmp(token, opco[i].opcode);
		if (op == 0)
			return (opco[i].f);
		i++;
	}
	return (opco[8].f);
}
/**
 * s_error - manage the error if instruction is invalid
 * @stack: pointer to top/head
 * @line_number: line number
 */
void s_error(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, global.content);
	free(global.content);
	fclose(global.file);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
