#include "shell.h"

/**
 * *_strncat - two string concatenated
 * @dest: first string
 * @src: secondstring
 * @n: total bytes to be maximally used
 * Return: string concatenated
 */
char *_strncat(char *dest, char *src, int n)
{
	int num, k;
	char *v = dest;

	num = 0;
	k = 0;
	while (dest[num] != '\0')
	num++;
	while (src[k] != '\0' && k < n)
	{
	dest[num] = src[k];
	num++;
	k++;
	}
	if (k < n)
	dest[num] = '\0';
	return (v);
}

/**
 * *_strncpy - string copies
 * @dest: string destination to be copied
 * @n: number of character to be copied
 * @src: string source
 * Return: string concatenated
 */
char *_strncpy(char *dest, char *src, int n)
{
	int num, k;
	char *v = dest;

	num = 0;
	while (src[num] != '\0' && num < n - 1)
	{
	dest[num] = src[num];
	num++;
	}
	if (num < n)
	{
	k = num;
	while (k < n)
	{
	dest[k] = '\0';
	k++;
	}
	}
	return (v);
}

/**
 * *_strchr - charater in string located
 * @s: string to be parsed
 * @c: look for character
 * Return: (s) pointer to memory area s
 */
char *_strchr(char *s, char c)
{
	do {
	if (*s == c)
	return (s);
	} while (*s++ != '\0');

	return (NULL);
}
