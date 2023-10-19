#include "shell.h"

/**
 * _mycd - current direction of the process changed
 * @info: potential struture arguments contained, to maintain
 *         constant function prototype
 * Return: 0 always
 */
int _mycd(info_t *info)
{
	char *c, *dir, buffer[1024];
	int chdir_ret;

	c = getcwd(buffer, 1024);
	if (!c)
	_puts("TOWHAT: >>getcwd failure msg here<<\n");
	if (!info->argv[1])
	{
	dir = _getenv(info, "SAFE=");
	if (!dir)
	chdir_ret = /* TOWHAT: what should this be? */
	chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
	else
	chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
	if (!_getenv(info, "OLDPWD="))
	{
	_puts(c);
	_putchar('\n');
	return (1);
	}
	_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
	chdir_ret = /* TOWHAT: what should this be? */
	chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
	chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
	print_error(info, "cant't cd to ");
	_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
	_setenv(info, "OLDPWD", _getenv(info, "PWD="));
	_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myexit - shell exit
 * @info: potential struture arguments contained, to
 *         maintain constant function prototype
 * Return: exit with given status (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1])
	{
	exitcheck = _erratoi(info->argv[1]);
	if (exitcheck == -1)
	{
	info->status = 2;
	print_error(info, "Illegal number: ");
	_eputs(info->argv[1]);
	_eputchar('\n');
	return (1);
	}
	info->err_num = _erratoi(info->argv[1]);
	return (-2);
	}
	info->err_num = -1;
	return (-2);
}


/**
 * _myhelp - changes the direction of the process
 * @info: potential struture argument contained, to
 *         maintain constant fuction prototype
 * Return: 0 always
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call work function not yet implemented \n");
	if (0)
	_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
