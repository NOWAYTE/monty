#include "monty.h"
/**
 * _mul - multiplies the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _mul(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);

		free(bus.content);
		free_stack(*head);

		exit(EXIT_FAILURE);
	}
	h = *head;
	ax = h->next->n * h->n;

	h->next->n = ax;
	*head = h->next;

	free(h);
}
/**
 * _add - adds top elements
 * @head: head
 * @counter: l_number
 * Return: no return type
*/
void _add(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);

		free(bus.content);

		free_stack(*head);

		exit(EXIT_FAILURE);
	}
	h = *head;
	ax = h->n + h->next->n;

	h->next->n = ax;


	*head = h->next;

	free(h);
}

