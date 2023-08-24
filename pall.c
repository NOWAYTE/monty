#include "monty.h"
/**
 * pall - prints all the values on the stack starting
 * from top of the stack
 * @s: double pointer
 * @n: integer parameter
 * Return: does have a return type
 */

void pall(stack_t **s, unsigned int n)
{
	stack_t *current = *s;

	while (current != NULL)
	{
		
		printf("%d\n", current->n);
		current = current->next;
		
	}

}
