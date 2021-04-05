#include "holberton.h"

int main(void)
{
	pid_t child;
	int status, err = 0, n;
	size_t len = 0; 
	char **argv;
	char *line = NULL;
	

	while(1 == 1)
	{
		write(1, "($) ", 4);
		getline(&line, &len, stdin);
		argv = parser(line);
		child = fork();
		if (child == -1)
			return (1);
		if (child == 0)
		{
			err = execve(argv[0], argv, NULL);
			if (err == -1)
			{
				n = strlen(argv[0]);
				write(1, "error: ", 7);
				write(1, argv[0], n);
				write(1, ": command not found\n", 20);
			}
				
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
