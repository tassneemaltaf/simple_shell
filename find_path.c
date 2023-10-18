#include "main.h"
/**
 * find_path - finds a path of a certain command
 * @command: the command which path is to be found
 * @env: the array of the current environment
 * Return: the path to the especified command
 * or NULL if the path is not found
 */
char *find_path(char *command, char *env[])
{
	int i = 0;
	char *path, *dir, *path_token;
	struct stat st;

	if (command == NULL)
		return (NULL);

	while (env[i] != NULL)
	{
		if (_strcmp(env[i], "PATH=", 5) == 0)
		{
			path = malloc(_strlen(env[i]));
			_strcpy(path, env[i] + 5);
			path_token = strtok(path, ":");
			while (path_token != NULL)
			{
				dir = malloc(sizeof(char) * _strlen(path_token) + 2 + _strlen(command));
				_strcpy(dir, path_token);
				_strcat(dir, "/", 1);
				_strcat(dir, command, _strlen(command));
				if (stat(dir, &st) == 0)
				{
					free(path);
					return (dir);
				}
				path_token = strtok(NULL, ":");
				free(dir);
			}

			free(path);
			break;
		}
		i++;
	}

	return (NULL);
}
