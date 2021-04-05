#include "holberton.h"

char **parser(char *str)
{
        size_t len, j = 0;
        char **res;
        char *word;

        len = _strlen(str);
        res = malloc(sizeof(char) * len);
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
