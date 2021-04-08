#include "holberton.h"

/**
 * exit_hsh - Entry point
 * @eof: eof
 * @argv0: command
 * description: handles different cases where user want to exit shell
 * Return: 0
 */

int exit_hsh(ssize_t eof, char **argv, int flag, char *line)
{
	int i = 0;

	if (eof == EOF)
	{
		if(flag == 1)
			_putchar('\n');
		return (0);
	}
	if (argv[0])
	{
		if (_strcmp(argv[0], "exit") == 0)
		{
			if(argv[1])
			{
				i = atoi(argv[1]);
				free_everything(line, argv);
				exit(i);
			}
			else
				return (0);
		}

		if ((_strcmp(argv[0], "env") == 0) && argv[1] == NULL)
		{
			for (i = 0; environ[i] != '\0' ; i++)
				_puts(environ[i]);
		}
	}
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
 * interactive - Entry point
 * @f: command
 * description: returns according to interactive mode
 * Return: void
 */

int interactive(int f)
{
	if (!isatty(STDIN_FILENO))
		f = 0;
	if (isatty(STDIN_FILENO))
		write (1, "($) ", 4);
	return (f);
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

	while (1 == 1)
	{
		f = interactive(f);
		eof = getline(&line, &len, stdin);
		free(argv);
		argv = parser(line);
		if ((exit_hsh(eof, argv, f, line)) == 0)
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
			if (argv[0])
				if (execve(_which(argv[0]), argv, NULL) == -1)
					perror("./hsh");
			break;
		}
		else
			wait(&status);
		fflush(STDIN_FILENO);
	}
	free_everything(line, argv);
	return (0);
}
