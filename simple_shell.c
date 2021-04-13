#include "holberton.h"

/**
 * built_ins - Entry point
 * @argv: command
 * @line: line
 * @env: enviroment array
 * @envi: pointer to enviromnet array
 * description: handles different cases where user want to exit shell
 * Return: 0
 */

int built_ins(char **argv, char *line, char **env, char ***envi)
{
	int exit_status = 0;

	if (argv[0])
	{
		if (_strcmp(argv[0], "exit") == 0)
		{
			if (argv[1])
			{
				exit_status = _atoi(argv[1]);
				free_everything(line, argv, env);
				exit(exit_status);
			}
			else
				return (0);
		}
		if (_strcmp(argv[0], "env") == 0)
		{
			env_builtin(argv, env);
			return (1);
		}
		if ((_strcmp(argv[0], "setenv") == 0) && argv[1] != NULL && argv[2] != NULL)
		{
			_setenv(argv[1], argv[2], 1, env, envi);
			argv[0] = NULL;
			return (1);
		}
	}
	return (1);
}

/**
 * free_everything - Entry point
 * @line: eof
 * @argv: command
 * @env: enviroment array
 * description: sets some variables to null and frees allocs
 * Return: void
 */

void free_everything(char *line, char **argv, char **env)
{	
	free_grid(env);
	free(line);
	line = NULL;
	free(argv);
}

/**
* sig_handler - Entry point
* @signum: signum
*
* Description: Hanndle the Ctrl+C signal
* Return: Nothing
*/
void sig_handler(int signum)
{
	signum = signum;
	write(1, "\n($) ", 5);
}

/**
 * interactive - Entry point
 * @f: command
 * description: returns according to interactive mode
 * Return: void
 */

int interactive(size_t f)
{
	if (!isatty(STDIN_FILENO))
		f = 0;
	if (isatty(STDIN_FILENO))
		write(1, "($) ", 4);
	return (f);
}


/**
 * main - Entry point
 * @argc: arg count
 * @argv: arg vector
 * description: main
 * Return: 0
 */

int main(int argc __attribute__((unused)), char **argv)
{
	pid_t child = 100;
	int eof = 0, status = 0;
	size_t len = 0, f = 1;
	char **args = NULL, **my_envi;
	char *line = NULL;

	my_envi = array_copy(environ, 0);
	while (1 == 1)
	{
		f = interactive(f);
		signal(SIGINT, sig_handler);
		eof = getline(&line, &len, stdin);
		if (ctrl_d(eof, f) == 0)
			break;
		free(args);
		args = parser(line);
		if ((built_ins(args, line, my_envi, &my_envi)) == 0)
		{
			fflush(STDIN_FILENO);
			break;
		}
		child = fork();
		if (child == -1)
		{
			free_everything(line, args, my_envi);
			return (1);
		}
		if (child == 0)
		{
			if (args[0])
				if (execve(_which(args[0], my_envi), args, NULL) == -1)
					perror(argv[0]);
			break;
		}
		else
			wait(&status);
		fflush(STDIN_FILENO);
	}
	free_everything(line, args, my_envi);
	return (0);
}
