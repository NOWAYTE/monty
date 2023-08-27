#include "monty.h"
/**
 * a_node - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
*/
void a_node(stack_t **head, int n)
{

	stack_t *n_node, *ax;

	ax = *head;
	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (ax)
		ax->prev = n_node;
	n_node->n = n;
	n_node->next = *head;
	n_node->prev = NULL;
	*head = n_node;
}
