#include "shell.h"

/**
 * _myhistory - One command at a time, preceded by a line number beginning at 0
 * is displayed in the history list.
 * @info: Layout with possible arguments used to retain
 * a prototype constant function
 * Return: 0 Always
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - This sets alias to string
 * @str: String alias
 * @info: The parameter structure
 * Return: On success 0 Always, on error 1
 */
int unset_alias(info_t *info, char *str)
{
	char *q, d;
	int ret;

	q = _strchr(str, '=');
	if (!q)
		return (1);
	d = *q;
	*q = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*q = d;
	return (ret);
}

/**
 * set_alias - This sets alias to string
 * @str: String alias
 * @info: The parameter structure
 * Return: On success 0 Always , on error 1
 */
int set_alias(info_t *info, char *str)
{
	char *q;

	q = _strchr(str, '=');
	if (!q)
		return (1);
	if (!*++q)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - This prints an alias string
 * @node: Alias node
 * Return: On success 0 Always, on error 1
 */
int print_alias(list_t *node)
{
	char *q = NULL, *b = NULL;

	if (node)
	{
		q = _strchr(node->str, '=');
		for (b = node->str; b <= q; b++)
			_putchar(*b);
		_putchar('\'');
		_puts(q + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - This mimics the alias builtin (man alias)
 * @info: Layout with possible arguments used to retain
 * a prototype constant function
 * Return: 0 Always
 */
int _myalias(info_t *info)
{
	int j = 0;
	char *q = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (j = 1; info->argv[j]; j++)
	{
		q = _strchr(info->argv[j], '=');
		if (q)
			set_alias(info, info->argv[j]);
		else
			print_alias(node_starts_with(info->alias, info->argv[j], '='));
	}

	return (0);
}
