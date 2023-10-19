#include "shell.h"

/**
 * _puts - input string printed
 * @str:string printed
 *
 * Return: NOTHING
 */
void _puts(char *str)
{
	int num = 0;

	if (!str)
	return;
	while (str[num] != '\0')
	{
	_putchar(str[num]);
	num++;
	}
}

/**
 * _strcpy - string copied
 * @src: sorce
 * @dest: destination:
 *
 * Return: destination pointer
 */
char *_strcpy(char *dest, char *src)
{
int num = 0;

if (dest == src || src == 0)
return (dest);
while (src[num])
{
dest[num] = src[num];
num++;
}
dest[num] = 0;
return (dest);
}

/**
 * _putchar - character c written to stdout
 * @c: print character
 *
 * Return: 1 on success
 * -1 is returned on error
 */
int _putchar(char c)
{
	static int num;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || num >= WRITE_BUF_SIZE)
	{
	write(1, buf, num);
	num = 0;
	}
	if (c != BUF_FLUSH)
	buf[num++] = c;
	return (1);
}

/**
 * _strmap - string duplicate
 * @str: strint to duplicate
 *
 * Return: duplicated string pointer
 */
char *_strmap(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
	return (NULL);
	while (*str++)
	length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
	return (NULL);
	for (length++; length--;)
	ret[length] = *--str;
	return (ret);
}
