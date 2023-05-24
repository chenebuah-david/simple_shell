#include "phics.h"
/**
 * _getenv - get environmental variable
 * @name: This is the name of variable
 * Return: This returns NULL or char *
 */

char *_getenv(const char *name)
{
	size_t length = _strlen(name);
	char **env = NULL;

	if (name == NULL || *name == '\0')
	{
		return (NULL);
	}
	for (env = environ; *(env) != NULL; env++)
	{
		if (_strncmp(name, *(env), length) == 0 && (*env)[length] == '=')
		{
			return (&(*env)[length + 1]);
		}
	}
	perror("getenv");
	return (NULL);
}
