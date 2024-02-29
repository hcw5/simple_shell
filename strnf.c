#include "shell.h"

/**
 * strngcop - Function that copys str.
 * @destn: Destination subject.
 * @srce: Source subject.
 * Return: Ptr to destination.
 */
char *strngcop(char *destn, char *srce)
{
	int h = 0;

	if (destn == srce || srce == 0)
		return (destn);
	while (srce[h])
	{
		destn[h] = srce[h];
		h++;
	}
	destn[h] = 0;
	return (destn);
}

/**
 * strngclone - Funtion duplicetes strng.
 * @strr: Strng undar dublication.
 * Return: Ptr to result strng.
 */
char *strngclone(const char *strr)
{
	int lngth = 0;
	char *retn;

	if (strr == NULL)
		return (NULL);
	while (*strr++)
		lngth++;
	retn = malloc(sizeof(char) * (lngth + 1));
	if (!retn)
		return (NULL);
	for (lngth++; lngth--;)
		retn[lngth] = *--strr;
	return (retn);
}

/**
 *strngin - Ensures input str tb printed.
 *@sstr: Printrd strng.
 * Return: void.
 */
void strngin(char *sstr)
{
	int n = 0;

	if (!sstr)
		return;
	while (sstr[n] != '\0')
	{
		_putchar(sstr[n]);
		n++;
	}
}

/**
 * _putchar - Function writes char to standard output console.
 * @charinp: Char tb printed.
 * Return: success 1 else, 0.
 */
int _putchar(char charinp)
{
	static int k;
	static char buff[WRITE_BUFFER_SIZE];

	if (k == BUFFER_FLUSH || k >= WRITE_BUFFER_SIZE)
	{
		write(1, buff, k);
		k = 0;
	}
	if (charinp != BUFFER_FLUSH)
		buff[k++] = charinp;
	return (1);
}
