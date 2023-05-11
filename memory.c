#include "shell.h"

/**
 * bfree - It frees a pointer
 * @ptr: The address of the pointer that is to be freed
 *
 * Return: 1 if freed, else 0 if not freed.
 */

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
