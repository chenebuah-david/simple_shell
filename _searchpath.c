#include "shell.h"

/**
* search_path - searches to see if a path is accessible and executable
* @cmd: command line input
* @paths: an array of paths from the environment
* @npaths:the number of paths
* Return: returns a pointer to the COMPLETE path and (NULL) on failure
*/

char *search_path(char *cmd, char *paths[], int npaths)
{
	int i = 0;

	if (access(cmd, X_OK) == 0)
	{
		return (strdup(cmd));
	}
	else
	{
		for (i = 0; i < npaths; i++)
		{
			char path[MAX_CMD_LENGTH];

			snprintf(path, MAX_CMD_LENGTH, "%s/%s", paths[i], cmd);
			if (access(path, X_OK) == 0)
			{
				return (strdup(path));
			}
		}
		return (NULL);
	}
}
