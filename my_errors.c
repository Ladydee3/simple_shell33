#include "shell.h"

/**
 * _putfd - character c to given fd written
 * @fd: filedescriptor to write to
 * @c: print character
 *
 * Return: 1 on success.
 * errno is set appropriate and -1 is returned on error
 */
int _putfd(char c, int fd)
{
	static int num;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || num >= WRITE_BUF_SIZE)
	{
	write(fd, buf, num);
	num = 0;
	}
	if (c != BUF_FLUSH)
	buf[num++] = c;
	return (1);
}

/**
 * _eputs - input string printed
 * @str: string to be printed
 *
 * Return: nothing
 */
void _eputs(char *str)
{
int num = 0;

if (!str)
return;
while (str[num] != '\0')
{
_eputchar(str[num]);
num++;
}
}

/**
 * _putsfd - input string printed
 * @fd: filedescriptor to write to
 * @str: printed string
 *
 * Return: chars put number
 */
int _putsfd(char *str, int fd)
{
	int num = 0;

	if (!str)
	return (0);
	while (*str)
	{
	num += _putfd(*str++, fd);
	}
	return (num);
}

/**
 * _putchar - character c written to stderr
 * @c: print character
 *
 *  Return: 1 0n success
 *  enno is set apropriate and -1 is returned on error
 */
int _putchar(char c)
{
	static int num;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || num >= WRITE_BUF_SIZE)
	{
	write(2, buf, num);
	num = 0;
	}
	if (c != BUF_FLUSH)
	buf[num] = c;
	return (1);
}
