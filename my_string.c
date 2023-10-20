#include "shell.h"

/**
 * _strcmp - comparison of two strings perfomed
 * @s1: first string
 * @s2: second string
 *
 * Return: if s1 == s2 zero
 *         if s1 < s2 negative
 *         if s1 > s2 positive
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
	if (*s1 != *s2)
	return (*s1 - *s2);

	s1++;
	s2++;
	}
	if (*s1 == *s2)
	return (0);
	else
	return (*s1 < *s2 ? -1 : 1);
}

/**
 * _strlen - length of string returned
 * @s: string length to check
 *
 * Return:string length integer
 */
int _strlen(char *s)
{
	int num = 0;

	if (!s)
	return (0);

	while (*s++)
	num++;
	return (num);
}

/**
 * _strcat - two string concatenated
 * @src: buffer source
 * @dest: buffer destination
 *
 * Return: buffer destination pointer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
	dest++;
	while (*src)
	*dest++ = *src++;
	*dest = *src;
	return (ret);
}

/**
 * begin_with - check if needle start with haystack
 * @needle: substring to find
 * @haystack: search string
 *
 * Return: next char of haystack address or NULL
 */
char *begin_with(const char *haystack, const char *needle)
{
	while (*needle)
	if (*needle++ != *haystack++)
	return (NULL);
	return ((char *)haystack);
}
