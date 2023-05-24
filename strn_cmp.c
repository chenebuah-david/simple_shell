#include "phics.h"
/**
 * _strncmp - This compares two strings
 * @m: The number of bytes to be checked
 * @s1: The first string
 * @s2: The second string
 * Return: This returns an integer
 */

int _strncmp(const char *s1, char *s2, size_t m)
{
	size_t j = 0;
	int flag = 0;

	for (j = 0; j < m; j++)
	{
		if (s1[j] != s2[j])
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		return (0);
	return (s1[j] - s2[j]);
}
