#include "shell.h"

/**
 * _atoi - integer string converted
 * @v: string to be converted
 * Return: converted number otherwise, if no numbers in string 0
 */
int _atoi(char *v)
{
	int num, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (num = 0; v[num] != '\0' && flag != 2; num++)
	{
	if (v[num] == '-')
	sign *= -1;

	if (v[num] >= '0' && v[num] <= '9')
	{
	flag = 1;
	result += (v[num] - '0');
	result *= 10;
	}
	else if (flag == 1)
	flag = 2;
	}
	if (sign == -1)
	output =  result;
	else
	output = -result;
	return (output);
}

/**
 * is_delim - character checked if its delimeter
 * @x: char to check
 * @delim: string delimeter
 * Return: if true 1, 0 on false
 */
int is_delim(char x, char *delim)
{
while (*delim)
if (*delim++ == x)
return (1);
return (0);
}

/**
 * _isalpha - alphabetic character checked
 * @x: input character
 * Return: if x is alphabetic 1, otherwise 0
 */
int _isalpha(int x)
{
	if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
	return (1);
	else
	return (0);
}

/**
 * interactive - if shell is interactive mode return true
 * @info: address struct
 *
 * Return: interactive mode 1, otherwise 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

