#include "holberton.h"
void env_builtin(char **argv)
{
	int i = 0;
		if ((_strcmp(argv[0], "env") == 0) && argv[1] == NULL)
                {
                        for (i = 0; my_env[i] != '\0' ; i++)
                                _puts(my_env[i]);
                        argv[0] = NULL;
			return;
                }
                if ((_strcmp(argv[0], "env") == 0) && argv[1] != NULL)
                {
                        for (i = 1 ; argv[i] != '\0' ; i++)
                                _strcpy(argv[i - 1], argv[i]);
                        argv[i - 1] = NULL;
                }
}

int replace_env_val(char *name, char *value, int pos)
{
	int size = 0;
	char *new_val;

	size = (_strlen(name) + 2 + _strlen(value));
                                        new_val = malloc(sizeof(char) * size);
                                        if(!new_val)
                                                return (-1);
                                        _strcpy(new_val, name);
                                        _strcat(new_val, "=");
                                        _strcat(new_val, value);
                                        _strcat(new_val , "\0");
                                        free(my_env[pos]);
                                        my_env[pos] = malloc(sizeof(char) * size);
                                        _strcpy(my_env[pos], new_val);
                                        free(new_val);
	return (0);
}
