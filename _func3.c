#include "monty.h"
/**
  *_rotr- rotates the stack to the bottom
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void _rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
/**
  *_rotl- rotates the stack to the top
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void _rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *ax;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	ax = (*head)->next;
	ax->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = ax;
}
/**
 * _stack - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bs.lifi = 0;
}
/**
 * _swap - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int l = 0, ax;

	h = *head;
	while (h)
	{
		h = h->next;
		l++;
	}
	if (l < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bs.file);
		free(bs.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	ax = h->n;
	h->n = h->next->n;
	h->next->n = ax;
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

