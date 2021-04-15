#include "holberton.h"
/**
* help - Entry point
*
* Description: help help
* Return: Nothing
*/
void help(void)
{
	_puts("		hsh help | hsh version: 1.0.1\n");
	_puts("		Usage: command_name [parameter]\n");
	_puts("		To help especific built-in type 'help name_of_built-in' ");
	_puts("\n");
	_puts("		cd [dir]\n");
	_puts("		env\n");
	_puts("		exit [status]\n");
	_puts("		help [built-in]\n");
	_puts("		setenv [name] [value]\n");
}
/**
* setenvh - Entry point
*
* Description: setenv help
* Return: Nothing
*/
void setenvh(void)
{
	_puts("		setenv built-in\n");
	_puts("\n");
	_puts("		Usage: setenv [name] [value]\n");
	_puts("		Set a enviroment variable [name] with value [value]\n");
	_puts("		If the variable already exists, replace the value\n");
	_puts("		Is not, add it to the enviroment\n");
}
/**
* cd - Entry point
*
* Description: cd help
* Return: Nothing
*/
void cd(void)
{
	_puts("		cd built-in\n");
	_puts("\n");
	_puts("		Usage: cd [dir]\n");
	_puts("		Change working directory\n");
	_puts("		You can use absolute or relative paths\n");
	_puts("		cd - goes to previusly folder\n");
	_puts("		cd without arguments goes to user home folder\n");
}
/**
* help_builtin - Entry point
* @args: arguments vector
*
* Description: Handle help built-in
* Return: Nothing
*/
void help_builtin(char **args)
{
	if (_strcmp(args[0], "help") == 0)
	{
		if (!args[1])
			help();
		else if (_strcmp(args[1], "cd") == 0)
			cd();
		else if (_strcmp(args[1], "env") == 0)
		{
			_puts("		env built-in\n");
			_puts("\n");
			_puts("		Print all the enviroment variables\n");
		}
		else if (_strcmp(args[1], "exit") == 0)
		{
			_puts("		exit built-in\n");
			_puts("\n");
			_puts("		Usage: exit [status]\n");
			_puts("		Exit the shell\n");
			_puts("		If status is specified, shell exit with exit code [status]\n");
		}
		else if (_strcmp(args[1], "setenv") == 0)
			setenvh();
		args[0] = NULL;
	}
}
