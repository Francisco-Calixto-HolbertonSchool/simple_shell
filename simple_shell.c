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
 * exit_hsh - Entry point
 * @eof: eof
 * @argv0: command
 * description: handles different cases where user want to exit shell
 * Return: 0
 */

void exit_hsh(ssize_t eof, char *argv0)
{
	if (eof == EOF)
	{
		_putchar('\n');
		exit(0);
	}
	if (_strcmp(argv0, "exit") == 0)
		exit(0);
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
		f = 0;
	while (1 == 1)
	{
		if (isatty(0))
			write(1, "($) ", 4);
		eof = getline(&line, &len, stdin);
		argv = parser(line);
		exit_hsh(eof, argv[0]);
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
			wait(&status);
		fflush(stdin);
		line = NULL;
		if (f == 0)
			break;
	}
	return (0);
}
