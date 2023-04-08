#include "monty.h"

/**
 * main - The entrance of the monty program
 * @ac: argument count
 * @av: the arguments from the CLI
 *
 * Return: exit_status
 */

int main(int ac, char **av)
{
	FILE *file;
	int exit_status = EXIT_SUCCESS;
	char *filename;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = av[1];
	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	exit_status = check_line(file);
	fclose(file);
	return (exit_status);
}
