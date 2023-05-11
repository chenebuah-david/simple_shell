#include "shell.h"

/**
 * list_len - This determines length of linked list
 * @i: This points to first node
 * Return: size of list
 */
size_t list_len(const list_t *i)
{
	size_t j = 0;

	while (i)
	{
		i = i->next;
		j++;
	}
	return (j);
}

/**
 * list_to_strings - This returns an array of strings of the list->str
 * @head: This points to first node
 * Return: The array of strings
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t j = list_len(head), k;
	char **strs;
	char *str;

	if (!head || !j)
		return (NULL);
	strs = malloc(sizeof(char *) * (j + 1));
	if (!strs)
		return (NULL);
	for (j = 0; node; node = node->next, j++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (k = 0; k < j; k++)
				free(strs[k]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[j] = str;
	}
	strs[j] = NULL;
	return (strs);
}


/**
 * print_list - This prints all elements of a list_t linked list
 * @i: This points to first node
 * Return: The size of list
 */
size_t print_list(const list_t *i)
{
	size_t j = 0;

	while (i)
	{
		_puts(convert_number(i->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(i->str ? i->str : "(nil)");
		_puts("\n");
		i = i->next;
		j++;
	}
	return (j);
}

/**
 * node_starts_with - This returns node whose string starts with prefix
 * @node: The pointer to list head
 * @prefix: The string to match
 * @d: Next character after prefix to match
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char d)
{
	char *q = NULL;

	while (node)
	{
		q = starts_with(node->str, prefix);
		if (q && ((d == -1) || (*q == d)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - This gets index of a node
 * @head: This points to the list head
 * @node: This points to node
 * Return: -1 or index of node
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t j = 0;

	while (head)
	{
		if (head == node)
			return (j);
		head = head->next;
		j++;
	}
	return (-1);
}
