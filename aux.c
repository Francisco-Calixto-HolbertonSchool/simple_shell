#include "holberton.h"

int count_dirs(char *path) /* Para para el PATH */
{
	int count = 3, i = 0; /* Count es 3 por PATH , la primer carpeta, y nulo*/
	for(i = 0 ; path[i] != '\0' ; i++)
	{
		if (path[i] == ':')
			count++;
	}
	return (count);
}

int count_sep(char *str, char sep) /* Para contar separadores (universal) */
{
	int count = 0, i = 0;
	for(i = 0 ; str[i] != '\0' ; i++)
	{
		if (str[i] == sep)
			count++;
	}
	return (count);
}

char **parser(char *str)
{
        size_t j = 0, sep = 0;
        char **res = NULL;
        char *word = NULL;

	sep = count_sep(str, ' ');
	res = malloc(sizeof(char *) * (sep + 2));
	word = strtok(str, " \n");
	while (word)
	{
		res[j] = word;
		word = strtok(NULL, " \n");
		j++;
	}
	res[j] = NULL;
	return (res);
}
/*
void free_array(char **argv)
{
	int i = 0;

	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
}
*/
