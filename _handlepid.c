#include "phics.h"
/**
 * do_pid - This is the function that handles execution of the full path
 * @env: This is the environmental variable
 * @pid: This is the pid of forked process
 * @args: This the array of command and the arguments
 * @cmd: This is the first token entered in the command line
 * @fullpath: This is the full path of the command
 * Return: This returns void
 */

void do_pid(pid_t pid, char *cmd, char *fullpath, char *args[], char **env)
{
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0 && fullpath != NULL)
	{
		execve(fullpath, args, env);
		perror("execve");
		free(cmd);
		exit(0);
	}
	else
	{
		wait(NULL);
	}
}
