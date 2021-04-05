#include "holberton.h"

/**
 * error_msg - Entry point
 * @err: execve return value
 * @name: argv[0]
 * description: prints error message
 * Return: nothing
 */

void error_msg(int err, char *name)
{
	int n;

	if (err == -1)
	{
		n = _strlen(name);
		write(1, "error: ", 7);
		write(1, name, n);
		write(1, ": command not found\n", 20);
	}
}

/**
 * main - Entry point
 * description: main
 * Return: 0
 */

int main(void)
{
	pid_t child = 5;
	int status, err = 0;
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
		if (eof == EOF)
                {
                        _putchar('\n');
                        break;
                }
		if (_strcmp(argv[0], "exit") == 0)
			break;
		child = fork();
		if (child == -1)
			return (1);
		if (child == 0)
		{
			err = execve(argv[0], argv, NULL);
			error_msg(err, argv[0]);
			break;
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
