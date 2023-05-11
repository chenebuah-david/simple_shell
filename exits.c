#include "shell.h"

/**
 * _strncpy - This copies string
 * @dest: Destination string to be copied to
 * @src: Source string
 * @m: Number of characters to be copied
 * Return: Concatenated string
 */
char *_strncpy(char *dest, char *src, int m)
{
	int j, k;
	char *t = dest;

	j = 0;
	while (src[j] != '\0' && j < m - 1)
	{
		dest[j] = src[j];
		j++;
	}
	if (j < m)
	{
		k = j;
		while (k < m)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (t);
}

/**
 * _strncat - This concatenates two strings
 * @dest: the first string
 * @m: Number of bytes to be maximally used
 * @src: Second string
 * Return: Concatenated string
 */
char *_strncat(char *dest, char *src, int m)
{
	int j, k;
	char *t = dest;

	j = 0;
	k = 0;
	while (dest[j] != '\0')
		j++;
	while (src[k] != '\0' && k < m)
	{
		dest[j] = src[k];
		j++;
		k++;
	}
	if (k < m)
		dest[j] = '\0';
	return (t);
}

/**
 * _strchr - This locates character in string
 * @d: Character to look for
 * @t: String to be parsed
 *Return: (t) pointer to memory area t
 */
char *_strchr(char *t, char d)
{
	do {
		if (*t == d)
			return (t);
	} while (*t++ != '\0');

	return (NULL);
}
