#include "shell.h"

/**
 * _erratoi - This converts string to integer
 * @t: String to be converted
 * Return: If no numbers in string 0,
 * converted number otherwise on error - 1
 */
int _erratoi(char *t)
{
	int j = 0;
	unsigned long int result = 0;

	if (*t == '+')
		t++;  /* TODO: why does this make main return 255? */
	for (j = 0;  t[j] != '\0'; j++)
	{
		if (t[j] >= '0' && t[j] <= '9')
		{
			result *= 10;
			result += (t[j] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - This prints error message
 * @estr: string containing specified error type
 * @info: Parameter & return information structure
 * Return: If no numbers in string 0,
 * converted number otherwise on error - 1
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - The function prints decimal (integer) number (base 10)
 * @fd: the filedescriptor to write to
 * @input: Input
 * Return: The number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int j, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (j = 1000000000; j > 1; j /= 10)
	{
		if (_abs_ / j)
		{
			__putchar('0' + current / j);
			count++;
		}
		current %= j;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - This converters function, clone of itoa
 * @flags: The argument flags
 * @num: The number
 * @base: The base
 * Return: The string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long m = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		m = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[m % base];
		m /= base;
	} while (m != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - The function replaces the first instance of '#' with '\0'
 * @buf: The address of string to modif
 * Return: 0 Always
 */
void remove_comments(char *buf)
{
	int j;

	for (j = 0; buf[j] != '\0'; j++)
		if (buf[j] == '#' && (!j || buf[j - 1] == ' '))
		{
			buf[j] = '\0';
			break;
		}
}
