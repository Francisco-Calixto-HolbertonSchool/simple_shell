#include "holberton.h"
/**
 * main - Entry point
 * description: main
 * Return: 0
 */

int main(void)
{
	pid_t child;
	int status, err = 0, n;
	size_t len = 0, f = 1;
	ssize_t eof;
	char **argv;
	char *line = NULL;

	if (!isatty(0))
	{
		f = 0;
	}
	while (1 == 1)
	{
		write(1, "($) ", 4);
		eof = getline(&line, &len, stdin);
		argv = parser(line);
		if ((eof == EOF) || (_strcmp(argv[0], "exit") == 0))
		{
			if (eof == EOF)
				_putchar('\n');
			break;
		}
		child = fork();
		if (child == -1)
			return (1);
		if (child == 0)
		{
			err = execve(argv[0], argv, NULL);
			if (err == -1)
			{
				n = _strlen(argv[0]);
				write(1, "error: ", 7);
				write(1, argv[0], n);
				write(1, ": command not found\n", 20);
			}
		}
		else
		{
			wait(&status);
		}
		fflush(stdin);
		line = NULL;
		if (f == 0)
			break;
	}
	return (0);
}
