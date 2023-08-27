#include "monty.h"
/**
 * f_swap - adds top elements
 * @head: head
 * @counter: l_number
 * Return: no return
*/
void f_swap(stack_t **head, unsigned int counter)
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
		fclose(bus.file);

		free(bus.content);

		free_stack(*head);

		exit(EXIT_FAILURE);
	}
	h = *head;
	ax = h->n;

	h->n = h->next->n;
	h->next->n = ax;
}
/**
  *f_nop- nothing
  *@head: head
  *@counter: l_number
  *Return: no return type
 */
void f_nop(stack_t **head, unsigned int counter)
{
	(void) counter;

	(void) head;
}
/**
 * f_pstr - prints the starting string
 * @head: head
 * @counter: l_number
 * Return: no return type
*/
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
/**
 * f_stack - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_stack(stack_t **head, unsigned int counter)
{
	(void)head;

	(void)counter;

	bus.lifi = 0;
}


/**
 * f_div - divides the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_div(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);

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

	ax = h->next->n / h->n;
	h->next->n = ax;

	*head = h->next;

	free(h);
}

