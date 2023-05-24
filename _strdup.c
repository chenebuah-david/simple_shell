#include "phics.h"

/**
 * _strdup - duplicate a string
 * @str: string to dupulicate
 *
 * Return: new string
 */

char *_strdup(char *str)
{
	int i;
	char *new_str = NULL;

	for (i = 0; str[i] != '\0'; i++)
		;
	new_str = malloc(sizeof(char) * i);
	for (i = 0; str[i] != '\0'; i++)
		new_str[i] = str[i];
	new_str[i] = '\0';
	return (new_str);
}
