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
	{
		printf("Error\n");
		exit(0);
	}

	if (ax)
		ax->prev = n_node;

	n_node->n = n;

	n_node->next = *head;

	n_node->prev = NULL;

	*head = n_node;
}
/**
  *_sub- sustration
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void _sub(stack_t **head, unsigned int counter)
{
	stack_t *ax;

	int s, n;

	ax = *head;

	for (n = 0; ax != NULL; n++)

		ax = ax->next;

	if (n < 2)
	{

		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);

		free(bus.content);

		free_stack(*head);

		exit(EXIT_FAILURE);
	}

	ax = *head;
	s = ax->next->n - ax->n;

	ax->next->n = s;
	*head = ax->next;
	free(ax);
}
/**
 * _pall - prints stack
 * @head: stack head
 * @counter: no used
 * Return: no return
*/
void _pall(stack_t **head, unsigned int counter)
{
	stack_t *h;

	(void)counter;

	h = *head;
	if (h == NULL)
		return;

	while (h)
	{

		printf("%d\n", h->n);

		h = h->next;
	}
}
/**
 * _pop - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);

		free(bus.content);

		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
/**
  *_rotr- rotates the stack to the bottom
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void _rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *c;

	c = *head;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (c->next)
	{
		c = c->next;

	}
	c->next = *head;

	c->prev->next = NULL;


	c->prev = NULL;
	(*head)->prev = c;

	(*head) = c;
}

