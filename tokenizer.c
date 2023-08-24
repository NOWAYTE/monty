#include "monty.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    stack_t *stack = NULL; /* Initialize an empty stack */
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;

    while (getline(&line, &len, file) != -1)
    {
        line_number++;

        /* Tokenize the line to extract opcode and argument (if any) */
        char *opcode = strtok(line, " \t\n"); /* Extract the first token (opcode) */
        char *arg = strtok(NULL, " \t\n"); /* Extract the second token (argument) */

        /* Find the corresponding function for the opcode */
        void (*opcode_func)(stack_t **, unsigned int) = NULL;
        instruction_t instructions[] = {
            {"push", push},
            {"pall", pall},
            /* Add more opcodes and their functions here */
        };
        size_t num_instructions = sizeof(instructions) / sizeof(instructions[0]);

        for (size_t i = 0; i < num_instructions; i++)
        {
            if (strcmp(opcode, instructions[i].opcode) == 0)
            {
                opcode_func = instructions[i].f;
                break;
            }
        }

        /* Check if the opcode was found */
        if (opcode_func == NULL)
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
            /* TODO: Free the stack and exit with status EXIT_FAILURE */
        }

        /* Call the opcode function */
        opcode_func(&stack, line_number);

        /* Free the line and reset the variables for the next iteration */
        free(line);
        line = NULL;
        len = 0;
    }

    free(line); /* Free the last allocated line (if any) */

    /* TODO: Free the stack before exiting */

    fclose(file);
    return 0;
}
