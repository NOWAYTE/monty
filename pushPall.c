#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
    /* Extract the argument and check if it's a valid integer */
    char *arg = strtok(NULL, " \t\n");
    if (arg == NULL)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        /* TODO: Free the stack and exit with status EXIT_FAILURE */
    }

    int value;
    if (sscanf(arg, "%d", &value) != 1)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        /* TODO: Free the stack and exit with status EXIT_FAILURE */
    }

    /* Create a new stack node */
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        /* TODO: Free the stack and exit with status EXIT_FAILURE */
    }

    /* Initialize the new node */
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    /* Update the previous node (if any) */
    if (*stack != NULL)
        (*stack)->prev = new_node;

    /* Update the stack pointer */
    *stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
