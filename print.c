#include "main.h"

/**
 * print - prints a message to the standart output
 * @message: the message to print
 * Return: nothing
 */
void print(char *message)
{
	write(1, message, _strlen(message));
}

/**
 * int_to_string - converts an int to a string
 * @number: the number to be converted
 * Return: the number as a string
 */
char *int_to_string(int number)
{
	int temp = number;
	int size = 0;
	int i;
	char *result;

	while (temp != 0)
	{
		temp /= 10;
		size++;
	}

	result = (char *)malloc(size + 1);
	if (result == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	for (i = size - 1; i >= 0; i--)
	{
		result[i] = '0' + (number % 10);
		number /= 10;
	}

	result[size] = '\0';

	return (result);
}

/**
 * print_error - prints an error message to the standard error
 * example of an error  message: ./hsh: 1: lsr: not found
 * @command: the mispelled command from the user (lsr in the example bellow)
 * @message: the error message (not found in the example bellow)
 * @filename: the name of the program (./hsh in the example bellow)
 * @err_no: the error number (1 in the example bellow)
 * Return: nothing
 */
void print_error(char *command, char *message, char *filename, int err_no)
{
	char *err_msg;
	char *err_no_str;

	err_no_str = int_to_string(err_no);
	err_msg = malloc(_strlen(command) + _strlen(message) +
			_strlen(filename) + _strlen(err_no_str) + 7);
	if (err_msg == NULL)
	{
		perror("malloc");
		return;
	}

	_strcpy(err_msg, filename);
	_strcat(err_msg, ": ", 2);
	_strcat(err_msg, err_no_str, _strlen(err_no_str));
	_strcat(err_msg, ": ", 2);
	_strcat(err_msg, command, _strlen(command));
	_strcat(err_msg, ": ", 2);
	_strcat(err_msg, message, _strlen(message));
	_strcat(err_msg, "\n", 1);

	write(STDERR_FILENO, err_msg, strlen(err_msg));

	free(err_no_str);
	free(err_msg);
}

/**
 * _printenv - prints the current environment
 * @env: the array of environment variables
 * Return: nothing
 */
void _printenv(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		print(env[i]);
		print("\n");
		i++;
	}
}
