#include "shell.h"

/**
 * mod_strng - Splits str
 * @strng: Structure denoting possible args
 * @spec: Delimeter
 * Return: Ptr
 */
char **mod_strng(char *strng, char *spec)
{
	int a, b, q, z, linesay = 0;
	char **stst;

	if (strng == NULL || strng[0] == 0)
		return (NULL);
	if (!spec)
		spec = " ";
	for (a = 0; strng[a] != '\0'; a++)
		if (!prser(strng[a], spec) && (prser(strng[a + 1], spec) || !strng[a + 1]))
			linesay++;

	if (linesay == 0)
		return (NULL);
	stst = malloc((1 + linesay) * sizeof(char *));
	if (!stst)
		return (NULL);
	for (a = 0, b = 0; b < linesay; b++)
	{
		while (prser(strng[a], spec))
			a++;
		q = 0;
		while (!prser(strng[a + q], spec) && strng[a + q])
			q++;
		stst[b] = malloc((q + 1) * sizeof(char));
		if (!stst[b])
		{
			for (q = 0; q < b; q++)
				free(stst[q]);
			free(stst);
			return (NULL);
		}
		for (z = 0; z < q; z++)
			stst[b][z] = strng[a++];
		stst[b][z] = 0;
	}
	stst[b] = NULL;
	return (stst);
}

/**
 * checkstrn - Splits str
 * @strng: Structure denoting multiple args
 * @spec: Delimeter
 * Return: Ptr
 */
char **checkstrn(char *strng, char spec)
{
	int a, b, q, z, linesay = 0;
	char **stst;

	if (strng == NULL || strng[0] == 0)
		return (NULL);
	for (a = 0; strng[a] != '\0'; a++)
		if ((strng[a] != spec && strng[a + 1] == spec) ||
		    (strng[a] != spec && !strng[a + 1]) || strng[a + 1] == spec)
			linesay++;
	if (linesay == 0)
		return (NULL);
	stst = malloc((1 + linesay) * sizeof(char *));
	if (!stst)
		return (NULL);
	for (a = 0, b = 0; b < linesay; b++)
	{
		while (strng[a] == spec && strng[a] != spec)
			a++;
		q = 0;
		while (strng[a + q] != spec && strng[a + q] && strng[a + q] != spec)
			q++;
		stst[b] = malloc((q + 1) * sizeof(char));
		if (!stst[b])
		{
			for (q = 0; q < b; q++)
				free(stst[q]);
			free(stst);
			return (NULL);
		}
		for (z = 0; z < q; z++)
			stst[b][z] = strng[a++];
		stst[b][z] = 0;
	}
	stst[b] = NULL;
	return (stst);
}
