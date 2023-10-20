#include "shell.h"

/**
 * bfree - it NULLs the address and rees pointer
 * @ptr: pointer address freed
 *
 * Return: 1 if freed, else 0
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
	free(*ptr);
	*ptr = NULL;
	return (1);
	}
	return (0);
}
