#include "shell.h"

/**
 * input_buf - This buffers chained commands
 * @buf: The address of buffer
 * @info: The parameter struct
 * @len: address of len var
 * Return: The bytes read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t s = 0;
	size_t len_p = 0;

	if (!*len) /* if nothing left in the buffer, fill it */
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		s = getline(buf, &len_p, stdin);
#else
		s = _getline(info, buf, &len_p);
#endif
		if (s > 0)
		{
			if ((*buf)[s - 1] == '\n')
			{
				(*buf)[s - 1] = '\0'; /* remove trailing newline */
				s--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*len = s;
				info->cmd_buf = buf;
			}
		}
	}
	return (s);
}

/**
 * get_input - This gets line minus the newline
 * @info: The parameter struct
 * Return: The bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buf; /* the ';' command chain buffer */
	static size_t j, k, len;
	ssize_t s = 0;
	char **buf_p = &(info->arg), *q;

	_putchar(BUF_FLUSH);
	s = input_buf(info, &buf, &len);
	if (s == -1) /* EOF */
		return (-1);
	if (len)	/* we have commands left in the chain buffer */
	{
		k = j; /* init new iterator to current buf position */
		q = buf + j; /* get pointer for return */

		check_chain(info, buf, &k, j, len);
		while (k < len) /* iterate to semicolon or end */
		{
			if (is_chain(info, buf, &k))
				break;
			k++;
		}

		j = k + 1; /* increment past nulled ';'' */
		if (j >= len) /* reached end of buffer? */
		{
			j = len = 0; /* reset position and length */
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = q; /* pass back pointer to current command position */
		return (_strlen(q)); /* return length of current command */
	}

	*buf_p = buf; /* else not a chain, pass back buffer from _getline() */
	return (s); /* return length of buffer from _getline() */
}

/**
 * read_buf - This reads buffer
 * @info: The parameter structure
 * @j: The size
 * Return: s
 */
ssize_t read_buf(info_t *info, char *buf, size_t *j)
{
	ssize_t s = 0;

	if (*j)
		return (0);
	s = read(info->readfd, buf, READ_BUF_SIZE);
	if (s >= 0)
		*j = s;
	return (s);
}

/**
 * _getline - This gets next line of input from STDIN
 * @length: size of preallocated ptr buffer if not NULL
 * @info: The parameter structure
 * @ptr: The pointer address to buffer, NULL or preallocated
 * Return: t
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t j, len;
	size_t l;
	ssize_t s = 0, t = 0;
	char *q = NULL, *new_p = NULL, *d;

	q = *ptr;
	if (q && length)
		t = *length;
	if (j == len)
		j = len = 0;

	s = read_buf(info, buf, &len);
	if (s == -1 || (s == 0 && len == 0))
		return (-1);

	d = _strchr(buf + j, '\n');
	l = d ? 1 + (unsigned int)(d - buf) : len;
	new_p = _realloc(q, t, t ? t + l : l + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (q ? free(q), -1 : -1);

	if (t)
		_strncat(new_p, buf + j, l - j);
	else
		_strncpy(new_p, buf + j, l - j + 1);

	t += l - j;
	j = l;
	q = new_p;

	if (length)
		*length = t;
	*ptr = q;
	return (t);
}

/**
 * sigintHandler - This blocks ctrl-C
 * @sig_num: Signal number
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
