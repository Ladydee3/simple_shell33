#include "shell.h"

/**
 * replace_vars - vars replaced in the tokenized string
 * @info: struct parameter
 *
 * Return: if replaced 1, otherwise 0
 */
int replace_vars(info_t *info)
{
	int num = 0;
	list_t *node;

	for (num = 0; info->argv[num]; num++)

	{
	if (info->argv[num][0] != '$' || !info->argv[num][1])
	continue;

	if (!_strcmp(info->argv[num], "$?"))
	{
	replace_string(&(info->argv[num]),
		_strmap(convert_number(info->status, 10, 0)));
	continue;
	}
	if (!_strcmp(info->argv[num], "$$"))
	{
	replace_string(&(info->argv[num], _strmap
			(convert_number(getpid(), 10, 0)));
	continue;
	}
	node = node_begin_with(info->env, &info->argv[num][1],
			'=');
	if (node)
	{
	replace_string(&(info->argv[num],
			_strmap(_strchr(node->str, '=') + 1));
	continue;
	}
	replace_string(&info->argv[num], _strmap(""));

	}
	return (0);
	}

/**
 * replace_string - string replaced
 * @old: old string address
 * @new: new string
 *
 * Return: 0 otherwise, 1 if replaced
 */
int replace_string(char **old, char *new)
{
free(*old);
*old = new;
return (1);
}

/**
 * is_chain - current char in buffer tested if is chain delimeter
 * @info: struct parameter
 * @buf: buffer char
 * @b: currenr address of position in buf
 *
 * Return: 0 otherwise, if chain delimeter  1
 */
int is_chain(info_t *info, char *buf, size_t *b)
{
	size_t k = *b;

	if (buf[k] == '|' && buf[k + 1] == '|')
	{
	buf[k] = 0;
	k++;
	info->cmd_buf_type = CMD_OR;
	}
	else if (buf[k] == '&' && buf[k + 1] == '&')
	{
	buf[k] = 0;
	k++;
	info->cmd_buf_type = CMD_AND;
	}
	else if (buf[k] == ';')
	{
	buf[k] = 0;
	info->cmd_buf_type = CMD_CHAIN;
	}
	else
	return (0);
	*b = k;
	return (1);
}

/**
 * check_chain - chaining based on last status
 * @info: struct parameter
 * @buf:buffer char
 * @b:current position in buf address
 * @num: starting position in buf
 * @len: buf length
 *
 * Return: void
 */
void check_chain(info_t *info, char *buf, size_t *b, size_t num, size_t len)
{
	size_t k = *b;

	if (info->cmd_buf_type == CMD_AND)
	{
	if (!info->status)
	{
	buf[num] = 0;
	k = len;
	}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
	if (!info->status)
	{
	buf[num] = 0;
	k = len;
	}
	}
	*b = k;
}

/**
 * replace_alias - aliases replaced in the tokenized string
 * @info: struct parameter
 *
 * Return: 0 otherwise, 1 if replaced
 */
int replace_alias(info_t *info)
{
	int num;
	list_t *node;
	char *b;

	for (num = 0; num < 10; num++)
	{
	node = node_begin_with(info->alias, info->argv[0],
		'=');
	if (!node)
	return (0);
	free(info->argv[0]);
	b = strchr(node->str, '=');
	if (!b)
	return (0);
	info->argv[0] = b;
	}
	return (1);
}


