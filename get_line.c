#include "phics.h"
#define MAX_PATH 256
/**
 * _getline - This gets line command
 * @m: This is 0
 * @ptr: This is the null terminated char *
 * @stm: This is the source
 * Return: characters read or -1
 */

ssize_t _getline(char **ptr, __attribute__((unused)) size_t *m, FILE *stm)
{
	char buff[MAX_PATH] = "";
	ssize_t read_count = 0;

	read_count = read(fileno(stm), buff, MAX_PATH);
	if (read_count == 0 || read_count == -1)
	{
		return (-1);
	}
	*ptr = malloc(sizeof(char) * MAX_PATH);
	_strcpy(*ptr, buff);
	return (read_count);
}
