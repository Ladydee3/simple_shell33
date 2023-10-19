#include "shell.h"

/**
 * ffree - string of strins freed
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **m = pp;

	if (!pp)
	return;
	while (*pp)
	free(*pp++);
	free(m);
}

/**
 * _realloc - block of memory reallocates
 * @old_size: previous block byte size
 * @new_size: new block new size
 * @ptr: malloc'ated block byte size
 *
 * Return: pointer to block name
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *b;

	if (!ptr)
	return (malloc(new_size));
	if (!new_size)
	return (free(ptr), NULL);
	if (new_size == old_size)
	return (ptr);

	b = malloc(new_size);
	if (!b)
	return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
	b[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (b);
}

/**
 * _memset - memory filled with constant byte
 * @n: bytes to be filled
 * @s:memory area ponter
 * @b:byte to fill *s with
 * Return: (s) memory area pointer s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int num;

	for (num = 0; num < n; num++)
	s[num] = b;
	return (s);
}
