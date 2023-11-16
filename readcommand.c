#include "shell.h"

/**
 **_memset - fills memory with a constant byte
 *@s: the pointer to the memory area
 *@b: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char by, unsigned int num)
{
	unsigned int i;

	for (i = 0; i < num; i++)
		s[i] = by;
	return (s);
}

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_byte: byte size of previous block
 * @new_byte: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_byte, unsigned int new_byte)
{
	char *p;

	if (!ptr)
		return (malloc(new_byte));
	if (!new_byte)
		return (free(ptr), NULL);
	if (new_byte == old_byte)
		return (ptr);

	p = malloc(new_byte);
	if (!p)
		return (NULL);

	old_byte = old_byte < new_byte ? old_byte : new_byte;
	while (old_byte--)
		p[old_byte] = ((char *)ptr)[old_byte];
	free(ptr);
	return (p);
}

