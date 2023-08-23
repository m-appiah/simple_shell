#include "shell.h"
#include <string.h>
#include <stdlib.h>

/**
 * _strcmp - function that compares two strings
 * @s1: first string parameter
 * @s2: second string parameter
 *
 * Return: Difference in s1 and s2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
/**
 * _strspn - function that gets the length of a prefix substring
 * @s: segment of strings
 * @accept: bytes
 *
 * Return: s
 */
int _strspn(char *s, char *accept)
{
	int bytes = 0;
	int i;

	while (*s)
	{
		for (i = 0; accept[i]; i++)
		{
			if (*s == accept[i])
			{
				bytes++;
				break;
			}
			else if (accept[i + 1] == '\0')
				return (bytes);
		}
		s++;
	}
	return (bytes);
}
/**
 * _strlen - function to return the length of a string
 * @s: input string
 *
 * Return: Always 0 (success)
 */
int _strlen(char *s)
{
	int counter = 0;

	while (*s != '\0')
	{
		s++;
		counter++;
	}
	return (counter);
}
/**
 * _strcpy - function that copies the string pointed to by src,
 * including the terminating null byte
 * @dest: parameter 1
 * @src: parameter 2
 *
 * Return: Always 0 (success)
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	int j = 0;

	while (*(src + j) != '\0')
	{
		j++;
	}
	for (i = 0; i < j; i++)
	{
		dest[i] = src[i];
	}
	dest[j] = '\0';
	return (dest);
}
/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: string pointer
 *
 * Return: pointer
 */
char *_strdup(char *str)
{
	int i, j;
	char *cpy_str;

	if (str == NULL)
	{
		return (NULL);
	}
	for (i = 0; str[i] != '\0'; i++)
		;

	cpy_str = malloc(i * sizeof(*cpy_str) + 1);

	if (cpy_str == NULL)
	{
		return (NULL);
	}
	for (j = 0; j < i; j++)
	{
		cpy_str[j] = str[j];
	}
	cpy_str[j] = '\0';
	return (cpy_str);
}
