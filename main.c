#include "main.h"

/**
 * just_spaces - verifies if a string only has spaces
 * @str: the string to be verified
 * Return: 1 if the string only has spaces or is null
 * return 0: if the string has at least one character
 */
int just_spaces(char *str)
{
	int i = 0;

	if (str == NULL)
		return (1);

	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (0);
		i++;
	}

	return (1);
}

/**
 * exe_cmd - executes a command
 * @tkns: the of tokens of the command
 * @fname: the name of the program
 * @env: the current environment
 * @cmd: the command typed by the user
 * @err: error number
 * Return: 0 on succes
 * return 2 on failure
 */
int exe_cmd(char **tkns, char *fname, char **env, char *cmd, int err)
{
	pid_t child;
	int status;

	if (tkns[0] != NULL)
	{
		child = fork();
		if (child == -1)
			exit(EXIT_FAILURE);
		else if (child == 0)
		{
			if (execve(tkns[0], tkns, env) == -1)
			{
				print_error(cmd, "not found", fname, err);
			}

		} else
			wait(&status);

	} else
	{
		print_error(cmd, "not found", fname, err);
	}

	return (WEXITSTATUS(status));
}

/**
 * main - the entry point of the program
 * @argc: the number of arguments
 * @argv: the array of arguments
 * @env: the current environment
 * Return: 0 (deafault)
 */
int main(int argc, char *argv[], char **env)
{
	char *prev_command, *buffer = NULL, **tokens, *delim = " \t\n";
	size_t buffer_size = 0;
	ssize_t read;
	struct stat st;
	int err_no = 0, status = 0;
	int interactive = isatty(STDIN_FILENO);
	(void) argc;

	while (1)
	{
		err_no++;
		if (interactive)
			print("$ ");
		read = getline(&buffer, &buffer_size, stdin);
		if (read == -1)
		{
			if (interactive)
				print_error("", "input err", argv[0], err_no);
			break;
		}
		if (interactive)
			buffer[read - 1] = '\0';
		if (_strcmp(buffer, "exit", 4) == 0)
			break;
		if (!just_spaces(buffer))
		{
			tokens = tokenize(buffer, delim);
			prev_command = tokens[0];
			if (stat(tokens[0], &st) != 0)
			{
				tokens[0] = find_path(tokens[0], env);
				status = exe_cmd(tokens, argv[0], env, prev_command, err_no);
				free(tokens[0]);
			} else
				status = exe_cmd(tokens, argv[0], env, prev_command, err_no);
			free(tokens);
		}
	}
	free(buffer);
	return (status);
}
