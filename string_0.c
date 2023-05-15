#include "shell.h"

/**
 * _strlen - This will return the length of a string
 * @s: This is the string whose length to check
 *
 * Return: The length of the string in integer
 */

int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - It performs comparison of two strangs.
 * @s1: the first string
 * @s2: the second string
 *
 * Return: positive if s1 > s2, Zero if s1 == s2 and negative if s1 < s2.
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystack: The string to search for
 * @needle: The substring that will be found
 *
 * Return: The address of next char of haystack
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - connect two strings
 * @src: The source buffer
 * @dest: The destination buffer
 *
 * Return: The pointer to the destination buffer
 */

char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
