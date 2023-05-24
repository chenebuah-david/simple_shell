#include "phics.h"
#define MAXCHAR 256

/**
* find_file_in_path - finds the full path
* @filename: command name
* @filepath: char array
* Return: char *(successuful) NULL (not successful)
*/

char *find_file_in_path(char *filename, char *filepath)
{
	char path[MAXCHAR];
	char *envpath = _getenv("PATH");

	char *__attribute__((unused))copy = strcpy(path, envpath);
	char *tok = strtok(path, ":");
	size_t  i = 0;
	size_t j = 0;

	if (access(filename, X_OK) != -1)
	{
		return (filename);
	}

	while (tok != NULL)
	{
		if (_strlen(tok) + _strlen(filename) + 2 <= MAXCHAR)
		{
			for (i = 0; i < _strlen(tok); i++)
			{
				filepath[i] = tok[i];
			}
				filepath[i] = '/';

			for (j = 0; j < _strlen(filename); j++)
			{
				filepath[i + j + 1] = filename[j];
			}
				filepath[i + j + 1] = '\0';

			if (access(filepath, X_OK) != -1)
			{
				return (filepath);
			}
		}

			tok = strtok(NULL, ":");
	}
		return (NULL);
}
