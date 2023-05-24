#include "phics.h"
/**
 * _strlen - This finds length of string
 * @t: String
 * Return: This returns a type of size_t
 */

size_t _strlen(const char *t)
{
	size_t j = 0;

	while (t[j] != '\0')
		j++;
	return (j);
}
