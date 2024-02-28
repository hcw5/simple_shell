#include "shell.h"

/**
 * actv_int - returns true as output if shell is interactive.
 * @feed: Address of the struct.
 * Return: 1 if successful else 0.
 */
int actv_int(pseuarg_ch *feed)
{
	return (isatty(STDIN_FILENO) && feed->telldes <= 2);
}

/**
 * prser - Delliminates a str.
 * @c: The char in examination.
 * @spec: Delimeter
 * Return: 1 for true else, 0.
 */
int prser(char c, char *spec)
{
	while (*spec)
		if (*spec++ == c)
			return (1);
	return (0);
}

/**
 *bst_int - Check character
 *@charinp: Inputt character
 *Return: 1 else, 0
 */
int bst_int(int charinp)
{
	if ((charinp >= 'a' && charinp <= 'z') || (charinp >= 'A' && charinp <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *genint - Generates an  integer from string
 *@s: Converted string
 *Return: 0 if unsuccessful.
 */
int genint(char *s)
{
	int a, hancock = 1, warn = 0, ans;
	unsigned int give = 0;

	for (a = 0;  s[a] != '\0' && warn != 2; a++)
	{
		if (s[a] == '-')
			hancock *= -1;

		if (s[a] >= '0' && s[a] <= '9')
		{
			warn = 1;
			give *= 10;
			give += (s[a] - '0');
		}
		else if (warn == 1)
			warn = 2;
	}

	if (hancock == -1)
		ans = -give;
	else
		ans = give;

	return (ans);
}
