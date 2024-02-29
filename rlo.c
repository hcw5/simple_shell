#include "shell.h"

/**
 **mmry_arn - Responsible for populatng memory.
 *@r: Ptr to memory.
 *@p: Reponsible byte for populatng memory.
 *@m: Bytes tb populated.
 *Return: Ptr to memory.
 */
char *mmry_arn(char *r, char p, unsigned int m)
{
	unsigned int l;

	for (l = 0; l < m; l++)
		r[l] = p;
	return (r);
}

/**
 * dmfree - Responsible freeing a str of strs.
 * @ss: Str of strs subject.
 */
void dmfree(char **ss)
{
	char **g = ss;

	if (!ss)
		return;
	while (*ss)
		free(*ss++);
	free(g);
}

/**
 * mem_ralloc - Responsible allocatng memory block.
 * @pptr: Ptr memory allocated block.
 * @init_size: Initial size of block memory.
 * @curr_size: Size of new mem allocated block.
 * Return: Ptr to memory block.
 */
void *mem_ralloc(void *pptr, unsigned int init_size, unsigned int curr_size)
{
	char *t;

	if (!pptr)
		return (malloc(curr_size));
	if (!curr_size)
		return (free(pptr), NULL);
	if (curr_size == init_size)
		return (pptr);

	t = malloc(curr_size);
	if (!t)
		return (NULL);

	init_size = init_size < curr_size ? init_size : curr_size;
	while (init_size--)
		t[init_size] = ((char *)pptr)[init_size];
	free(pptr);
	return (t);
}
