#include "holberton.h"

/**
 * _strlen - entry point
 * @s: string to find length
 * Return: length
 */

int _strlen(char *s)
{
	int len;

	if (s == NULL)
		return (0);
	for (len = 0; *s != 0; s++, len++)
	{
	}
	return (len);
}

/**
 * _strcmp - entry point
 * @s1: string 1 to be compared
 * @s2: string 2 to be compared
 * Return: 0 if equal, !0 if different
 */

int _strcmp(char *s1, char *s2)
{
	int a;
	int b;

	while (*s1 == *s2)
	{
		s1++;
		s2++;
		if (*s1 == '\0' || *s2 == '\0')
			break;
	}
	a = *s1;
	b = *s2;
	return (a - b);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print.
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
