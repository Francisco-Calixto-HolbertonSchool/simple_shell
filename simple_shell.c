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
	int n = 0;

	if (err == -1)
	{
		n = _strlen(name);
		write(STDOUT_FILENO, "error: ", 7);
		write(STDOUT_FILENO, name, n);
		write(STDOUT_FILENO, ": command not found\n", 20);
	}
}

/**
 * exit_hsh - Entry point
 * @eof: eof
 * @argv0: command
 * description: handles different cases where user want to exit shell
 * Return: 0
 */

size_t exit_hsh(ssize_t eof, char *argv0)
{
	if (eof == EOF)
	{
		_putchar('\n');
		return (0);
	}
	if (_strcmp(argv0, "exit") == 0)
		return (0);
	return (1);
}

/**
 * main - Entry point
 * description: main
 * Return: 0
 */

int main(void)
{
	pid_t child = 100; /* Para darnos cuenta si falla */
	int status = 0, err = 0;
	size_t len = 0, f = 1, b = 1;
	ssize_t eof = 0;
	char **argv = NULL;
	char *line = NULL;

	if (!isatty(STDIN_FILENO))
		f = 0;
	while (1 == 1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "($) ", 4);
		eof = getline(&line, &len, stdin);
		argv = parser(line);
		b = exit_hsh(eof, argv[0]);
		if (b == 0)
		{
			fflush(STDIN_FILENO);
			line = NULL;
			break;
		}
		child = fork();
		if (child == -1)
		{
			free(line);
			free_array(argv);
			return (1);
		}
		if (child == 0)
		{
			err = execve(argv[0], argv, NULL);
			error_msg(err, argv[0]);
			break;
		}
		else
			wait(&status);
		fflush(STDIN_FILENO);
		line = NULL;
		if (f == 0)
			break;
	}
	free(line);
	free_array(argv);
	return (0);
}
