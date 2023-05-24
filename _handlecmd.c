#include "phics.h"
/**
 * handle_cmd - Checks for special commands
 * @cmd: Command
 * @argv: The caller
 * @args: The array pointer
 * Return: This returns void
 */

int handle_cmd(char **args, char *argv, char *cmd)
{
	int result = 0, exit_status = 0;

	if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1] !=  NULL)
		{
			exit_status = atoi(args[1]);
			free(cmd);
			exit(exit_status);
		}
		free(cmd);
		exit(exit_status);
	}

	else if (_strcmp(args[0], "setenv") == 0)
	{
		if (args[3] == NULL)
		{
			result = _setenv(args[1], args[2], 0);
		}
		else
		{
			result = _setenv(args[1], args[2], atoi(args[3]));
		}
		if (result == 0)
		printf("success\n");
		return (1);
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		cd_dir(args[1], argv);
		return (1);
	}
	return (0);
}
