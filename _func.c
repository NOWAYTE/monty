#include "monty.h"
/**
 * _push - add node
 * @head: head
 * @counter: l_number
 * Return: no return
*/
void _push(stack_t **head, unsigned int counter)
{
	int n, j = 0, f = 0;
	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)

				f = 1;
		}
		if (f == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);

			fclose(bus.file);

			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{ 
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);

		free_stack(*head);

		exit(EXIT_FAILURE); 
	}
	n = atoi(bus.arg);
	if (bus.lifi == 0)

		a_node(head, n);
	else

		a_queue(head, n);
}
bus_t bus = {NULL, NULL, NULL, 0};
/**
* main - interpreter
* @argc: arguments
* @argv: location
* Return: 0 (success)
*/
int main(int argc, char *argv[])
{
	char *con;
	FILE *file;
	size_t s = 0;

	ssize_t r_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (r_line > 0)
	{
		con = NULL;
		r_line = getline(&con, &s, file);

		bus.content = con;

		counter++;

		if (r_line > 0)
		{
			execute(con, &stack, counter, file);
		}
		free(con);

	}


	free_stack(stack);

	fclose(file);


return (0);
}
/**
* execute - execute opcode
* @stack: head
* @counter: l_counter
* @file: pointer to monty
* @content: line content
* Return: no return type
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", _push}, {"pall", _pall}, {"pint", _pint},
				{"pop", _pop},
				{"swap", _swap},
				{"add", _add},
				{"nop", _nop},
				{"sub", _sub},
				{"div", _div},
				{"mul", _mul},
				{"mod", _mod},
				{"pchar", _pchar},
				{"pstr", _pstr},
				{"rotl", _rotl},
				{"rotr", _rotr},
				{"queue", _queue},
				{"stack", _stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");

	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)

	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);

		fclose(file);

		free(content);

		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}
/**
* free_stack - frees list
* @head: head 
*/
void free_stack(stack_t *head)
{
	stack_t *ax;

	ax = head;
	while (head)
	{
		ax = head->next;
		free(head);
		head = ax;
	}
}
/**
 * f_pchar - prints char at top,
 * @head: head
 * @counter: l_number
 * Return: no return type
*/
void f_pchar(stack_t **head, unsigned int counter)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);

		free(bus.content);

		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);

		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", h->n);
}

