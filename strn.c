#include "shell.h"

/**
 * lngth_str - Determines str leng
 * @r: Str
 * Return: Str leng
 */
int lngth_str(char *r)
{
	int a = 0;

	if (!r)
		return (0);

	while (*r++)
		a++;
	return (a);
}

/**
 * strn_cmp - Compares strs
 * @r1: Str 1
 * @r2: Str 2
 * Return: Str comparison
 */
int strn_cmp(char *r1, char *r2)
{
	while (*r1 && *r2)
	{
		if (*r1 != *r2)
			return (*r1 - *r2);
		r1++;
		r2++;
	}
	if (*r1 == *r2)
		return (0);
	else
		return (*r1 < *r2 ? -1 : 1);
}

/**
 * at_strt - Checks given requir
 * @getit: Str locate
 * @forme: String tb located
 * Return: Str
 */
char *at_strt(const char *getit, const char *forme)
{
	while (*forme)
		if (*forme++ != *getit++)
			return (NULL);
	return ((char *)getit);
}

/**
 * strn_cat - Str concatenator
 * @strngdest: Destination buff
 * @strngsrce: Source buff
 * Return: Destination ptr
 */
char *strn_cat(char *strngdest, char *strngsrce)
{
	char *rtrn = strngdest;

	while (*strngdest)
		strngdest++;
	while (*strngsrce)
		*strngdest++ = *strngsrce++;
	*strngdest = *strngsrce;
	return (rtrn);
}
