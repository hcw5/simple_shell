#include "shell.h"

/**
 * myown_env - Ensure current environment is printed.
 * @feed: Structure denoting possible arguments
 * Return: 0
 */
int myown_env(pseuarg_ch *feed)
{
	lststr_prnt(feed->exvar);
	return (0);
}

/**
 * pop_env - Obtain env variable values.
 * @feed: Structure denoting possible arguments
 * @vname: Variable name of env in subject.
 * Return: Environment variable values
 */
char *pop_env(pseuarg_ch *feed, const char *vname)
{
	lst_m *sect = feed->exvar;
	char *k;

	while (sect)
	{
		k = at_strt(sect->strng, vname);
		if (k && *k)
			return (k);
		sect = sect->next;
	}
	return (NULL);
}

/**
 * good_env - Configure new environment variables.
 * @feed: Structure denoting possible arguments
 * Return: 0
 */
int good_env(pseuarg_ch *feed)
{
	if (feed->argc != 3)
	{
		putide("Incorrect number of arguements\n");
		return (1);
	}
	if (ptenv(feed, feed->argv[1], feed->argv[2]))
		return (0);
	return (1);
}

/**
 * bad_env - deelete/removes env var.
 * @feed: Structure denoting possible arguments
 * Return: 0
 */
int bad_env(pseuarg_ch *feed)
{
	int d;

	if (feed->argc == 1)
	{
		putide("Too few arguements.\n");
		return (1);
	}
	for (d = 1; d <= feed->argc; d++)
		envunp(feed, feed->argv[d]);

	return (0);
}

/**
 * fill_env - Add to  env lst.
 * @feed: Structure denoting possible arguments
 * Return: 0
 */
int fill_env(pseuarg_ch *feed)
{
	lst_m *sect = NULL;
	size_t d;

	for (d = 0; environ[d]; d++)
		endnode_add(&sect, environ[d], 0);
	feed->exvar = sect;
	return (0);
}
