#include "phics.h"
/**
 * cd_dir - This changes directory
 * @name: This is the name of directory
 * @argv: This is the caller
 * Return: This returns 0
 */
int cd_dir(char *name, char *argv)
{
	int cd_checker;
	char buff[1024];

	if (name == NULL)
	{
		chdir(_getenv("HOME"));
		_setenv("OLDPWD", _getenv("PWD"), 1);
		_setenv("PWD", _getenv("HOME"), 1);
		return (0);
	}
	else if (_strcmp("-", name) == 0)
	{
		chdir(_getenv("OLDPWD"));
		_setenv("OLDPWD", _getenv("PWD"), 1);
		_setenv("PWD", getcwd(buff, 1024), 1);
		return (0);
	}
	else
	{
		cd_checker = chdir(name);
		if (cd_checker == -1)
		{
			perror(argv);
			return (0);
		}
		_setenv("OLDPWD", _getenv("PWD"), 1);
		_setenv("PWD", getcwd(buff, 1024), 1);
		return (0);
	}
	return (0);
}
