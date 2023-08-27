#include "monty.h"
/**
 * _pint -prints top
 * @head: head
 * @counter: l_number
 * Return: no return type
 */
void _pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bs.file);
		free(bs.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
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
		fclose(bs.file);
		free(bs.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
/**
 * p_str - prints the string starting at the top of the stack,
 * followed by a new
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void p_str(stack_t **head, unsigned int counter)
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
 * _push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (bs.arg)
	{
		if (bs.arg[0] == '-')
			j++;
		for (; bs.arg[j] != '\0'; j++)
		{
			if (bs.arg[j] > 57 || bs.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bs.file);
			free(bs.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bs.file);
		free(bs.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bs.arg);
	if (bs.lifi == 0)
		a_node(head, n);
	else
		a_queue(head, n);
}
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
