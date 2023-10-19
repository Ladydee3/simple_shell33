#include "shell.h"

/**
 * list_to_strings - return the list->str string array
 * @head: first node pointer
 *
 * Return: string array
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t num = list_len(head), k;
	char **strs;
	char *str;

	if (!head || !num)
	return (NULL);
	strs = malloc(sizeof(char *) * (num + 1));
	if (!strs)
	return (NULL);
	for (num = 0; node; node = node->next, num++)
	{
	str = malloc(_strlen(node->str) + 1);
	if (!str)
	{
	for (k = 0; k < num; k++)
	free(strs[k]);
	free(strs);
	return (NULL);
	}

	str = _strcpy(str, node->str);
	strs[num] = str;
	}
	strs[num] = NULL;
	return (strs);
}

/**
 * node_begin_with - node starts with prefix retured
 * @prefix: match string
 * @node: head  list pointer
 * @c: character to match after prefix
 *
 * Return: match node or null
 */
list_t *node_begin_with(list_t *node, char *prefix, char c)
{
	char *b = NULL;

	while (node)
	{
	b = begin_with(node->str, prefix);
	if (b && ((c == -1) || (*b == c)))
	return (node);
	node = node->next;
	}
	return (NULL);
}

/**
 * list_len - link list length dtermined
 * @h: first node pointer
 *
 * Return: list size
 */
size_t list_len(const list_t *h)
{
	size_t num = 0;

	while (h)
	{
	h = h->next;
	num++;
	}
	return (num);
}

/**
 * get_node_index - gets node index
 * @node: node pointer
 * @head: head list pointer
 *
 * Return: node index or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	ssize_t  num = 0;

	while (head)
	{
	if (head == node)
	return (num);
	head = head->next;
	num++;
	}
	return (-1);
}

/**
 * print_list - list_t linked list element  printed
 * @h:first node pointer
 *
 * Return: list size
 */
size_t print_list(const list_t *h)
{
	size_t num = 0;

	while (h)
	{
	_puts(convert_number(h->num, 10, 0));
	_putchar(':');
	_putchar(' ');
	_puts("\n");
	h = h->next;
	num++;
	}
	return (num);
}
