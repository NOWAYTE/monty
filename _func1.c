#include "monty.h"
/**
 * _mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
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
		fclose(bs.file);
		free(bs.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bs.file);
		free(bs.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ax = h->next->n % h->n;
	h->next->n = ax;
	*head = h->next;
	free(h);
}
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
		fclose(bs.file);
		free(bs.content);
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
  *_nop- nothing
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void _nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}

/**
 * _pall - prints the stack
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
 * p_char - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void p_char(stack_t **head, unsigned int counter)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bs.file);
		free(bs.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bs.file);
		free(bs.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
