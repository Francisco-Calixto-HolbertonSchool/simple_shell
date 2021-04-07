#include "holberton.h"

/**
 * exit_hsh - Entry point
 * @eof: eof
 * @argv0: command
 * description: handles different cases where user want to exit shell
 * Return: 0
 */

int exit_hsh(ssize_t eof, char *argv0)
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
 * free_everything - Entry point
 * @line: eof
 * @argv: command
 * description: sets some variables to null and frees allocs
 * Return: void
 */

void free_everything(char *line, char **argv)
{
	free(line);
	line = NULL;
	free(argv);
}

/**
 * main - Entry point
 * description: main
 * Return: 0
 */

int main(void)
{
	pid_t child = 100; /* Para darnos cuenta si falla */
	int status = 0;
	size_t len = 0, f = 1;
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
		free(argv);
		argv = parser(line);
		if ((exit_hsh(eof, argv[0])) == 0)
		{
			fflush(STDIN_FILENO);
			break;
		}
		child = fork();
		if (child == -1)
		{
			free_everything(line, argv);
			return (1);
		}
		if (child == 0)
		{
			if (execve(_which(argv[0]), argv, NULL) == -1)
				perror("./hsh");
			break;
		}
		else
			wait(&status);
		fflush(STDIN_FILENO);
		if (f == 0)
			break;
	}
	free_everything(line, argv);
	return (0);
}
