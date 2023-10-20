#include "shell.h"

/**
 * find_cmd - command in PATH found
 * @info: info struct and parameter return
 *
 * Return: void
 */
void find_cmd(info_t *info)
{
	char *path = NULL;
	int num, j;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
	info->line_count++;
	info->linecount_flag = 0;
	}
	for (num = 0; j = 0; info->arg[num]; num++)
	if (!is_delim(info->arg[num], " \t\n"))
	j++;
	if (!j)
	return;

	path = find_path(info, _getenv(info, "PATH="), info->arg[0]);
	if (path)
	{
	info->path = path;
	fork_cmd(info);
	}
	else
	{
	if ((interactive(info) || _getenv(info, "PATH=")
		|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
	fork_cmd(info);
	else if (*(info->arg) != '\n')
	{
	info->status = 127;
	print_error(info, "not found\n");
	}
	}
}

/**
 * hsh - shell loop mai
 * @av: vector from main () argument
 * @info: return info struct and parameter
 *
 * Return: 1 on error , 0 on success
 */
int hsh(info_t *info, char **av)
{
	ssize_t z = 0;
	int builtin_ret = 0;

	while (z != -1 && builtin_ret != -2)
	{
	clear_info(info);
	if (interactive(info))
	_puts("$ ");
	_eputchar(BUF_FLUSH);
	z = get_inputs(info);
	if (z != -1)
	{

	set_info(info, av);
	builtin_ret = find_builtin(info);
	if (builtin_ret == -1)
	find_cmd(info);
	}
	else if (interactive(info))
	_putchar('\n');
	free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
	exit(info->status);
	if (builtin_ret == -2)
	{
	if (info->err_num == -1)
	exit(info->status);
	exit(info->err_num);
	}
	return (builtin_ret);
}

/**
 * find_builtin - command for builtin found
 * @info: info struct return and parameter
 *
 * Return: if builtin not found  -1
 *         if builtin signal exit() -2
 *         if builtin is successfully executed 0
 *         1 if builtin not successful but found
 */
int find_builtin(info_t *info)
{
	int num, built_in_ret = -1;
	builtin_table builtin[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};
	for (num = 0; builtintbl[num].type; num++)
	if (_strcmp(info->argv[0], builtintbl[num].type)n == 0)
	{
	info->line_count++;
	built_in_ret = builtintbl[num].func(info);
	break;
	}
	return (built_in_ret);
}


/**
 * fork_cmd - an exec thread to run cmd forks
 * @info: info struct return n parameter
 *
 * Return: void
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
	/* TODO: PUT ERROR FUNCTION */
	perror("Error:");
	return;
	}
	if (child_pid == 0)
	{
	if (execve(info->path, info->argv, get_environ(info)) == -1)
	{
	free_info(info, 1);
	if (errno == EACCES)
	exit(126);
	exit(1);
	}
	}
	else
	{
	wait(&(info->status));
	if (WIFEXITED(info->status))
	{
	info->status = WEXITSTATUS(info->status);
	if (info->status == 126)
	print_error(info, "Permission denied\n");
	}
	}
}

