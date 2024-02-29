#include "shell.h"

/**
 * aqrenv - Returns environment arr
 * @feed: Structure denoting possible args
 * Return: 0
 */
char **aqrenv(pseuarg_ch *feed)
{
	if (!feed->environ || feed->new_env)
	{
		feed->environ = strng_lst(feed->exvar);
		feed->new_env = 0;
	}

	return (feed->environ);
}

/**
 * envunp - Gets rid of environment variable
 * @feed: Structure denoting possible args
 * @evible: Environment variable
 * Return: 1
 */
int envunp(pseuarg_ch *feed, char *evible)
{
	lst_m *sect = feed->exvar;
	size_t a = 0;
	char *q;

	if (!sect || !evible)
		return (0);

	while (sect)
	{
		q = at_strt(sect->strng, evible);
		if (q && *q == '=')
		{
			feed->new_env = indxnode_del(&(feed->exvar), a);
			a = 0;
			sect = feed->exvar;
			continue;
		}
		sect = sect->next;
		a++;
	}
	return (feed->new_env);
}

/**
 * ptenv - Sets & enhances environment variables
 * @feed: Structure denoting poss arg
 * @evible: Environment variable
 * @strev: String environment variable
 * Return: 0
 */
int ptenv(pseuarg_ch *feed, char *evible, char *strev)
{
	char *buff = NULL;
	lst_m *sect;
	char *q;

	if (!evible || !strev)
		return (0);

	buff = malloc(lngth_str(evible) + lngth_str(strev) + 2);
	if (!buff)
		return (1);
	strngcop(buff, evible);
	strn_cat(buff, "=");
	strn_cat(buff, strev);
	sect = feed->exvar;
	while (sect)
	{
		q = at_strt(sect->strng, evible);
		if (q && *q == '=')
		{
			free(sect->strng);
			sect->strng = buff;
			feed->new_env = 1;
			return (0);
		}
		sect = sect->next;
	}
	endnode_add(&(feed->exvar), buff, 0);
	free(buff);
	feed->new_env = 1;
	return (0);
}
