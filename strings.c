#include "main.h"

/**
 * _strcat - concatenates two strings.
 * @dest: the destination string
 * @src: the source string
 * @n: the number of bytes that will be concatened from src
 * Return:  a pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src, int n)
{
	int i, j, chr;

	i = 0;
	chr = dest[i];
	while (chr != '\0')
	{
		i++;
		chr = dest[i];
	}

	j = 0;
	chr = src[j];
	while (j < n && chr != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
		chr = src[j];
	}
	dest[i] = '\0';
	return (dest);
}



/**
 * _strlen - calculates the length of a string.
 * @s: the pointer to the string
 * Return: the length of a string.
 */
int _strlen(char *s)
{
	int i, len;

	i = *s;
	len = 0;
	while (i != '\0')
	{
		len++;
		i = *(s + len);
	}
	return (len);
}

/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest.
 * @dest: the destination pointer
 * @src: the source pointer
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i, chr;

	i = 0;
	chr = *src;
	while (chr !=  '\0')
	{
		dest[i] = chr;
		i++;
		chr = *(src + i);
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - compares the first n bytes of two strings.
 * @s1: the first string
 * @s2: the second string
 * @n: the number of bytes to be compared
 * Return:  0, if the first n bytes of s1 and s2 are equal;
 * If false return the difference between the first different character
 */
int _strcmp(char *s1, char *s2, int n)
{
	int i = 0;

	if (s1[0] == '\0')
		return (1);

	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
