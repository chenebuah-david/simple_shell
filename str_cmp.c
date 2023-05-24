#include "phics.h"
/**
 * _strcmp - This is the string compare
 * @s1: The first string
 * @s2: The second string
 * Return: int
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		break;

	}
	return (s1[i] - s2[i]);
}
