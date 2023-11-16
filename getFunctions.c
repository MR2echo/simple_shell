#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @t1: the first strang
 * @t2: the second strang
 *
 * Return: negative if t1 < t2, positive if t1 > t2, zero if t1 == t2
 */
int _strcmp(char *t1, char *t2)
{
	while (*t1 && *t2)
	{
		if (*t1 != *t2)
			return (*t1 - *t2);
		t1++;
		t2++;
	}
	if (*t1 == *t2)
		return (0);
	else
		return (*t1 < *t2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two strings
 * @desti: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *desti, char *src)
{
	char *ret = desti;

	while (*desit)
		desti++;
	while (*src)
		*desti++ = *src++;
	*desti = *src;
	return (ret);
}

