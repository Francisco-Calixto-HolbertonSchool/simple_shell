#include "holberton.h"
/**
* cd_env_val -Entry point
* @new: new PWD value
* @env: enviroment array
* @envi: pointer to enviroment
*
* Description: Change the enviroment variables used in cd
* Return: Nothing
*/
void cd_env_val(char *new, char **env, char ***envi)
{
	char *folder = NULL;

	folder = getcwd(folder, 0);
	_setenv("OLDPWD", folder, 1, env, envi);
	_setenv("PWD", new, 1, env, envi);
	free(folder);
}

/**
* cd_builtin - Entry point
* @argv: argument array
* @env: enviroment array
* @envi: pointer to enviroment
*
* Description: Logic of cd built-in command
* Return: Nothing
*/
void cd_builtin(char **argv, char **env, char ***envi)
{
	char *dog, *val = NULL, **local_env = NULL;

	if (_strcmp(argv[0], "cd") == 0)
	{
		local_env = array_copy(env, 0);
		if (argv[1] == NULL)
		{
			val = _getenv("HOME", local_env);
			strtok(val, "=");
			dog = strtok(NULL, "=");
			cd_env_val(dog, env, envi);
			chdir(dog);
		}
		else if (argv[1][0] == '/')
		{
			cd_env_val(argv[1], env, envi);
			chdir(argv[1]);
		}
		else if (argv[1][0] == '-')
		{
			val = _getenv("OLDPWD", local_env);
			strtok(val, "=");
			dog = strtok(NULL, "=");
			cd_env_val(dog, env, envi);
			chdir(dog);
		}
		else
		{
			cd_env_val(argv[1], env, envi);
			chdir(argv[1]);
			val = getcwd(val, 0);
			_setenv("PWD", val, 1, env, envi);
			free(val);
		}
		argv[0] = NULL;
		free_grid(local_env);
	}
}
