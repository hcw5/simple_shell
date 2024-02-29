#include "shell.h"

/**
 * mem_free - Liberates ptr and nullifies address.
 * @pttr: Liberated ptr address.
 * Return: 1 success, else 0.
 */
int mem_free(void **pttr)
{
	if (pttr && *pttr)
	{
		free(*pttr);
		*pttr = NULL;
		return (1);
	}
	return (0);
}
