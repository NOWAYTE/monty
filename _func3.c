#include "monty.h"
/**
  *_rotl- rotates the stack to the top
  *@head: head
  *@counter: line_number
  *Return: no return
 */
void _rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *t = *head, *ax;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	ax = (*head)->next;
	ax->prev = NULL
		;
	while (t->next != NULL)
	{
		t = t->next;
	}

	t->next = *head;

	(*head)->next = NULL;

	(*head)->prev = t;
	(*head) = ax;

}
/**
 * _pint - prints top
 * @head: head
 * @counter: line_number
 * Return: no return
*/
void _pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);


		free(bus.content);

		free_stack(*head);

		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}
/**
 * _queue - prints top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _queue(stack_t **head, unsigned int counter)
{
	(void)head;

	(void)counter;

	bus.lifi = 1;
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
/**
 * _mod - computes division
 * @head: head
 * @counter: l_number
 * Return: no return type
*/
void _mod(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);

		free(bus.content);

		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);

		free(bus.content);

		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	ax = h->next->n % h->n;
	h->next->n = ax;

	*head = h->next;

	free(h);
}

