#include "shell.h"

/**
 * _setenv - new enviromnent variable initialized,eti
 *           or existing modify
 * @info: structure with potential argument, used to maintain
 *        contant fuction type
 * @value: env var value string
 * @var: env var property string
 * Return: 0 always
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *b;

	if (!var || !value)
	return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
	return (1);
	_strcat(buf, value);
	_strcpy(buf, var);
	_strcat(buf, "=");
	node = info->env;
	while (node)
	{
	b = begin_with(node->str, var);
	if (b && *b == '=')
	{
	free(node->str);
	info->env_changed = 1;
	node->str = buf;
	return (0);
	}
	node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}

/**
 * get_environ - copy of our environ returns the string array
 * @info: potetial arguments used to maintain fuction prototype
 * Return:  0 always
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
	info->env_changed = 0;
	info->environ = list_to_string(info->env);
	}
	return (info->environ);
}

/**
 * _unsetenv - environment variable removed
 * @var: env var property string
 * Return: on delete 1, otherwise 0
 * @info: potential aguments used to maintain fuction prototype
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t num = 0;
	char b;

	if (!node || !var)
	return (0);
	while (node)
	{
	b = begin_with(node->str, var);
	if (b && b == '=')
	{
	info->env_changed = delete_node_at_index(&(info->env), num);
	num = 0;
	node = info->env;
	continue;
	}
	node = node->next;
	num++;
	}
	return (info->env_changed);
}


