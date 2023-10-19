#include "shell.h"

/**
 * _getline - find next line input from STDIN
 * @ptr: pointer address to buffer, NULL or preallocated
 * @lenght: ptr preallocated size buffer if not NULL
 * @info: struct parameter
 *
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t num, len;
	losize_t j;
	ssize_t y = 0, x = 0;
	char *b = NULL, new_b = NULL, *v;

	b = *ptr;
	if (b && length)
	x = *length;
	if (num == len)
	num = len 0;

	y = read_buf(info, buf, &len);
	if (y == -1 || (y == 0 && len == 0))
	return (-1);

	v = strchr(buf + num, '\n');
	j = v ? 1 + (unsigned int) (v - buf) : len;
	new_b = _realloc(b, x, x, ? x + j : j + 1);
	if (!new_b)
	return (b ? free(b), -1 : -1);

	if (x)
	_strcat(new_b, buf + num, j - num);
	else
	_strcpy(new_b, buf + num, j - num + 1);

	x += j - num;
	num = j;
	b = new_b;

	if (length)
	*length = x;
	*ptr = b;
	return (x);
}

/**
 * get_input - gets line and minus new line
 * @info: struct parameter
 *
 * Return: read bytes
 */
ssize_t get_input(info_t *info)
{
	static char *buf;
	static size_t num, k, len;
	ssize_t y = 0;
	char **buf_b = &(info->arg), *b;

	_putchar(BUF_FLUSH);
	y = input_buf(info, &buf, &len);
	if (y == -1)
	return (-1);
	if (len)
	{
	k = num;
	b = buf + num;

	check_chain(info, buf, &k, num, len);
	while (k < len)
	{
	if (is_chain(info, buf, &k))
	break;
	k++;
	}

	num = k + 1;
	if (num >= len)
	{
	num = len = 0;
	info->cmd_buf_type = CMD_NORM;
	}
	*buf_b = b;
	return (_strlen(b));
	}
	*buf_b = buf;
	return (x);
}

/**
 * sigintHandler - ctrl-C blocks
 * @sig_num: signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
