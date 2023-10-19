#include "shell.h"

/**
 * _myhistory - history list displayed
 * @info: potential structure arguments contained, to
 *         maintain function prototype
 * Return: 0 always
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * _myalias - alias builtin mimics
 * @info: potential structure arguments contained, to maintain
 *        function prototype
 * Return: 0 always
 */
int _myalias(info_t *info)
{
	int num = 0;
	char *b = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
	node = info->alias;
	while (node)
	{
	print_list(node);
	node = node->next;
	}
	return (0);
	}
	for (num = 1; info->argv[num]; num++)
	{
	b = _strchr(info->argv[num], '=');
	if (b)
	set_alias(info, info->argv[num]);
	else
	print_list(node_begin_with(info->alias, info->argv[num], '='));
	}
	return (0);
}
