#include "monty.h"
/**
 * push - pushed an element to the stack 
 * @stack: double pointer 
 * @value: value
 * Return: does not have a return value 
 *
 */
void push(stack_t **s, int v)
{
	stack_t n_node = malloc(sizeof(stack_t));

	if(n_node == NULL)
	{
		fprintf(stderr, "Error\n");

		exit(EXIT_FAILURE);
	}

	n_node->n = v;
	n_node->prev = NULL;

	if (*s != NULL)
	{

		n_node->nect = *s;
		(*s)->prev =  n_node;

	}
	else
	{
		n_node->next = NULL;

	}

	*s = n_node;

}
