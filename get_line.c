#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
/**
 * _getline - This reads a command and saves in the line
 * @cmd: This is a pointer to character pointer
 * @ptr: This is a pointer to the file of input
 * @m: This is the number of bytes
 * Return: This returns a pointer (success) NULL (faliure)
 */

char *_getline(char **cmd, size_t *m, FILE *ptr)
{
	static char buffer[1024];
	static size_t buffer_size;
	size_t len = 0;
	char *q = NULL;

*cmd = NULL;
*m = 0;

while (fgets(buffer, sizeof(buffer), ptr) != NULL)
{
	len = strlen(buffer);

	if (len > buffer_size)
	{
		buffer_size = len;
		q = (char *)realloc(*cmd, buffer_size);
		if (q == NULL)
		{
			free(*cmd);
			return (NULL);
		}
		*cmd = q;
		*m = buffer_size;
	}

memcpy(*cmd + *m - buffer_size, buffer, len);
buffer_size -= len;

	if (buffer[len - 1] == '\n')
	{
		(*cmd)[*n - 1] = '\0';
		return (*cmd);
	}
}

	if (*m > 0)
	{
		(*cmd)[*m - buffer_size] = '\0';
		return (*cmd);
	}
	else
	{
		return (NULL);
	}
}
