#include "factors.h"

int main(int ac, char *av[]);
int factorize(char *buffer);

/**
 * main - Entry point
 * @ac: Arguement count
 * @av: Arguement vector
 *
 * Return: 0 if success
 */
int main(int ac, char *av[])
{
	FILE *fd;
	size_t count;
	ssize_t line;
	char *buffer = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "Usage: factor <filename>\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	line = getline(&buffer, &count, fd);
	while (line != -1)
	{
		factorize(buffer);
		line = getline(&buffer, &count, fd);
	}
	return (0);
}

/**
 * factorize - Factorize number given
 * @buffer: Pointer address of number
 *
 * Return: Number
 */
int factorize(char *buffer)
{
	long unsigned int number;
	long unsigned int i;

	number = atoi(buffer);
	for (i = 2; i < number; i ++)
	{
		if (number % i == 0)
		{
			printf("%lu=%lu*%lu\n", number, number/i, i);
			break;
		}
	}
	return (0);
}
