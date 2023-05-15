#include "shell.h"

/**
 **_memset - This fills memory with continuous byte
 *@n: This is the amount of bytes that needs to be filled
 *@s: The major pointer of the memory area or address
 *@b: The byte to fill *s with
 *Return: (s) a pointer to the memory area or address s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int x;

	for (x = 0; x < n; x++)
		s[x] = b;
	return (s);
}

/**
 * ffree - frees up a string of strings
 * @pp: The string of strings
 */

void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - reallocates block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: The byte size of previous block
 * @new_size: The byte size of recent block
 *
 * Return: pointer to the previous block name.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
