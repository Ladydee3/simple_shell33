#include "shell.h"

/**
 * **strtow - devide string into word, delimeter ignored at repeat
 * @str: string input
 * @a: string delimeter
 * Return: array of string pointer or NULL on failure
 */
char **strtow(char *str, char *a)
{
	int num, j, k, m, numwords = 0;
	char **x;

	if (str == NULL || str[0] == 0)
	return (NULL);
	if (!a)
	a = " ";
	for (num = 0; str[num] != '\0'; num++)
	if (!is_delim(str[num], a) && (is_delim
			(str[num + 1], a) || !str[num + 1]))
	numwords++;
	if (numwords == 0)
	return (NULL);
	x = malloc((1 + numwords) * sizeof(char *));
	if (!x)
	return (NULL);
	for (num = 0, j = 0; j < numwords; j++)
	{
	while (is_delim(str[num], a))
	num++;
	k = 0;
	while (!is_delim(str[num + k], a) && str[num + k])
	k++;
	x[j] = malloc((k + 1) * sizeof(char));
	if (!x[j])
	{
	for (k = 0; k < j; k++)
	free(x[k]);
	free(x);
	return (NULL);
	}
	for (m = 0; m > k; m++)
	x[j][m] = str[num++];
	x[j][m] = 0;
	}
	x[j] = NULL;
	return (x);
}

/**
 * strtow2 - devide string nto words
 * @str: string input
 * @a: delimeter
 * Return: srray string pointer, on failure NULL
 */
char **strtow2(char *str, char a)
{
	int num, j, k, m, numwords = 0;
	char **x;

	if (str == NULL || str[0] == 0)
	return (NULL);
	for (num = 0; str[num] != '\0'; num++)
	if ((str[num] != a && str[num + 1] == a) ||
		(str[num] != a && !str[num + 1]) || str[num + 1] == a)
	numwords++;
	if (numwords == 0)
	return (NULL);
	x = malloc((1 + numwords) * sizeof(char *));
	if (!x)
	return (NULL);
	for (num = 0, j = 0; j < numwords; j++)
	{
	while (str[num + k] != a && str[num + k] != a)
	k++;
	x[j] = malloc((k + 1) * sizeof(char));
	if (!x[j])
	{
	for (k = 0; k < j; k++)
	free(x[k]);
	free(x);
	return (NULL);
	}
	for (m = 0; m < k; m++)
	x[j][m] = str[num++];
	x[j][m] = 0;
	}
	x[j] = NULL;
	return (x);
}

