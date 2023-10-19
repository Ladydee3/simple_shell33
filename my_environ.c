#include "shell.h"

/**
 * _myunsetenv - environment viriable renoved
 * @info: potetial structure arguments containing,to
 *         maintain constant fuction prototype
 * Return: 0 always
 */
int _myunsetenv(info_t *info)
{
	int num;

	if (info->argc == 1)
	{
	_eputs("Too few arguments.\n");
	return (1);
	}
	for (num = 1; num <= info->argc; num++)
	_unsetenv(info, info->argv[num]);

	return (0);
}

/**
 * _myenv - curent argument printed
 * @info: potetial structure argument containing, to
 *       maintain constant fuction prototype
 * Return: 0 always
 */
int _myenv(info_t *info)
{
	print_list_t_str(info->env);
	return (0);
}

/**
 * _getenv - finds value of environ variable
 * @name: the env var name
 * @info: potential argument structure cotained
 *
 * Return: value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *b;

	while (node)
	{
	b = begin_with(node->str, name);
	if (b && *b)
	return (b);
	node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - new enviromnent viriable initialized
 * @info: potetial argument structure containing, to maintai
 *       constant function prototype
 * Return: 0 always
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
	_eputs("wrong number of arguments\n");
	return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
	return (0);
	return (1);
}

/**
 * populate_env_list - env link list populated
 * @info: potential argument structure containing, to
 *       maintain constant fuction prototype
 * Return: 0 always
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t num;

	for (num = 0; environ[num]; num++)
	add_node_end(&node, environ[num], 0);
	info->env = node;
	return (0);
}
