#include "shell.h"

/**
 * build_history_list - entry added to link list
 * @buf: buffer
 * @info: potetial argument struture cotained, used to maitain
 * @linecount: history linecount, histcount
 *
 * Return: 0 always
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
	node = info->history;
	add_node_end(&node, buf, linecount);

	if (!info->history)
	info->history = node;
	return (0);
}

/**
 * write_history - create or appends to an existing file
 * @info: struct parameter
 *
 * Return: if success 1 otherwise -1
 */
int write_history(info_t *info)
{
ssize_t fd;
char *filename = get_history_file(info);
list_t *node = NULL;
if (!filename)
return (-10);

fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
free(filename);
if (fd == -1)
return (-1);
for (node = info->history; node; node = node->next)
{
_putsfd(node->str, fd);
_putfd('\n', fd);
}
_putfd(BUF_FLUSH, fd);
close(fd);
return (1);
}

/**
 * renumber_history - history linked list renumbered after changes
 * @info: potetial struture containing arguments, used to maintain
 *
 * Return: new histcount
 */
int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int num = 0;

	while (node)
	{
	node->num = num++;
	node = node->next;
	}
	return (info->histcount = num);
}

/**
 * read_history - history from file read
 * @info: struct parameter
 *
 * Return: on success histcount, else 0
 */
int read_history(info_t *info)
{
	int num, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(info);

	if (!filename)
	return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
	return (0);
	if (!fstat(fd, &st))
	fsize = st.st_size;
	if (fsize < 2)
	return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
	return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
	return (free(buf), 0);
	close(fd);
	for (num = 0; num < fsize; num++)
	if (buf[num] == '\n')
	{
	buf[num] = 0;
	build_history_list(info, buf + last, linecount++);
	last = num + 1;
	}
	if (last != num)
	build_history_list(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= LIST_MAX)
	delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}

/**
 * get_history_file - get history file
 * @info: struct parameter
 *
 * Return: string with history file allocated
 */
char *get_history_file(info_t *info)
{
	char *buf, *dir;

	dir = _getenv(info, "SAFE");
	if (!dir)
	return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(LIST_FILE) + 2));
	if (!buf)
	return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}

