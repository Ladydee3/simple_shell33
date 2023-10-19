#include "shell.h"

/**
 * is_cmd - checks if a file is exectable command
 * @path: struct info
 * @info: file path
 *
 * Return: 1 on true, otherwise 0
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
	return (0);

	if (st.st_mode & S_IFREG)
	{
	return (1);
	}
	return (0);
}

/**
 * map_chars - character duplicate
 * @start: index start
 * @stop: index stop
 * @pathstr: string PATH
 *
 * Return: new pointer buffer
 */
char *map_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int num = 0, j = 0;

	for (j = 0, num = start; num < stop; num++)
	if (pathstr[num] != ':')
	buf[j++] = pathstr[num];
	buf[j] = 0;
	return (buf);
}

/**
 * find_path - cmd found in the PATH string
 * @pathstr: string PATH
 * @info:struct info
 * @cmd:finf cmd
 *
 * Return: cmd path found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int num = 0, run_test = 0;
	char *path;

	if (!pathstr)
	return (NULL);
	if ((_strlen(cmd) > 2) && begin_with(cmd, "./"))
	{
	if (is_cmd(info, cmd))
	return (cmd);
	}
	while (1)
	{
	if (!pathstr[num] || pathstr[num] == ':')
	{
	path = map_chars(pathstr, run_test, num);
	if (!*path)
	_strcat(path, cmd);
	else
	{
	_strcat(path, "/");
	_strcat(path, cmd);
	}
	if (is_cmd(info, path))
	return (path);
	if (!pathstr[num])
	break;
	run_test = num;
	}
	num++;
	}
	return (NULL);
}
