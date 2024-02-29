#include "shell.h"

/**
 * exst_err - Generates int from str
 * @st: Str under transformation.
 * Return: 0 success, else -1
 */
int exst_err(char *st)
{
	int u = 0;
	unsigned long int give = 0;

	if (*st == '+')
		st++;
	for (u = 0;  st[u] != '\0'; u++)
	{
		if (st[u] >= '0' && st[u] <= '9')
		{
			give *= 10;
			give += (st[u] - '0');
			if (give > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (give);
}

/**
 * errorprnt - Returns error message as output
 * @feed: Str denoting multiple args
 * @errstrng: String denoting error
 * Return: 0 success, else -1
 */
void errorprnt(pseuarg_ch *feed, char *errstrng)
{
	putide(feed->progname);
	putide(": ");
	disprnt(feed->cnterr, STDERR_FILENO);
	putide(": ");
	putide(feed->argv[0]);
	putide(": ");
	putide(errstrng);
}

/**
 * disprnt - Prints int no. base 10.
 * @setit: Input subject.
 * @fd: Respective file descriptor to written to.
 * Return: Total no. printed chars.
 */
int disprnt(int setit, int fd)
{
	int (*__putchar)(char) = _putchar;
	int u, ccount = 0;
	unsigned int bs_arr, currnt;

	if (fd == STDERR_FILENO)
		__putchar = charins;
	if (setit < 0)
	{
		bs_arr = -setit;
		__putchar('-');
		ccount++;
	}
	else
		bs_arr = setit;
	currnt = bs_arr;
	for (u = 1000000000; u > 1; u /= 10)
	{
		if (bs_arr / u)
		{
			__putchar('0' + currnt / u);
			ccount++;
		}
		currnt %= u;
	}
	__putchar('0' + currnt);
	ccount++;

	return (ccount);
}

/**
 * conv_nmber - Function converts.
 * @numb: Num subject.
 * @base_s: Base subject.
 * @argflags: Arg flags subject.
 * Return: String char.
 */
char *conv_nmber(long int numb, int base_s, int argflags)
{
	static char *arr;
	static char bffer[50];
	char indic = 0;
	char *pter;
	unsigned long m = numb;

	if (!(argflags & CONVERT_UNINT) && numb < 0)
	{
		m = -numb;
		indic = '-';

	}
	arr = argflags & CONVERT_LOWER ? "0123456789abcdef" : "0123456789ABCDEF";
	pter = &bffer[49];
	*pter = '\0';

	do	{
		*--pter = arr[m % base_s];
		m /= base_s;
	} while (m != 0);

	if (indic)
		*--pter = indic;
	return (pter);
}

/**
 * rm_comm - Replaces first instance '#' wit null terminator..
 * @buff: Address str under modification.
 * Return: 0
 */
void rm_comm(char *buff)
{
	int r;

	for (r = 0; buff[r] != '\0'; r++)
		if (buff[r] == '#' && (!r || buff[r - 1] == ' '))
		{
			buff[r] = '\0';
			break;
		}
}
