#include "shell.h"

/**
 * add_node_end - node added to the end of the list
 * @str: field node
 * @num: index node used by history
 * @head: address pointer to head node
 *
 * Return: list size
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *node;

	if (!head)
	return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
	return (NULL);
	*_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
	new_node->str = _strmap(str);
	if (!new_node->str)
	{
	free(new_node);
	return (NULL);
	}
	}
	if (node)
	{
	while (node->next)
	node = node->next;
	node->next = new_node;
	}
	*head = new_node;
	return (new_node);
}

/**
 * print_list_str - only the str element of list_t linked list printed
 * @h:first node pointer
 * Return: list size
 */
size_t print_list_str(const list_t *h)
{
	size_t num = 0;

	while (h)
	{
	_puts(h->str ? h->str : "(nil)");
	_puts("\n");
	h = h->next;
	num++;
	}
	return (num);
}

/**
 * add_node - node added at the start of tje list
 * @num: index node used by history
 * @head: poiter address to head node
 * @str:strnode fiels
 *
 * Return: list size
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_head;

	if (!head)
	return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
	return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	if (str)
	{
	new_head->str = _strmap(str);
	if (!new_head->str)
	{
	free(new_head);
	return (NULL);
	}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * delete_node_at_index - node at given index deleted
 * @index: delete node index
 * @head: first node pointer address
 *
 * Return: on success 1, on failure 0
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int num = 0;

	if (!head || !*head)
	return (0);

	if (!index)
	{
	node = *head;
	free(node->str);
	*head = (*head)->next;
	free(node);
	return (1);
	}
	node = *head;
	while (node)
	{
	if (num == index)
	{
	prev_node->next = node->next;
	free(node->str);
	free(node);
	return (1);
	}
	num++;
	prev_node = node;
	node = node->next;
	}
	return (0);
}


/**
 * free_list - all node list freed
 * @head_ptr:  head note pointer address
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
	return;
	head = *head_ptr;
	node = head;
	while (node)
	{
	next_node = node->next;
	free(node->str);
	free(node);
	node = next_node;
	}
	*head_ptr = NULL;
}
