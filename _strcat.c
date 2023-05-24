#include "phics.h"
/**
 * _strcat - concantenate string
 * @s1: destination of the string
 * @s2: source of the string
 *
 * Return: 0
 */

char *_strcat(char *s1, char *s2)
{
	int i;
	int j;

	for (i = 0; s1[i] != '\0'; i++)
	;
	for (j = 0; s2[j] != '\0'; j++)
	{
		s1[i] = s2[j];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
