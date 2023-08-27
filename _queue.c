#include "monty.h"
/**
 * _queue - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bs.lifi = 1;
}
/**
 * a_queue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
*/
void a_queue(stack_t **head, int n)
{
	stack_t *n_node, *ax;

	ax = *head;
	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
	{
		printf("Error\n");
	}
	n_node->n = n;
	n_node->next = NULL;
	if (ax)
	{
		while (ax->next)
			ax = ax->next;
	}
	if (!ax)
	{
		*head = n_node;
		n_node->prev = NULL;
	}
	else
	{
		ax->next = n_node;
		n_node->prev = ax;
	}
}


