#include "shell.h"

/**
 * str_ch - Determines charr delimeter.
 * @feed: Structure denoting possible args.
 * @buff: Buffer subject.
 * @potr: Buffer curr position address.
 * Return: 1 success,else 0.
 */
int str_ch(pseuarg_ch *feed, char *buff, size_t *potr)
{
	size_t k = *potr;

	if (buff[k] == '|' && buff[k + 1] == '|')
	{
		buff[k] = 0;
		k++;
		feed->cdbuffertype = OR_CMND;
	}
	else if (buff[k] == '&' && buff[k + 1] == '&')
	{
		buff[k] = 0;
		k++;
		feed->cdbuffertype = AND_CMND;
	}
	else if (buff[k] == ';')
	{
		buff[k] = 0;
		feed->cdbuffertype = CHAIN_CMND;
	}
	else
		return (0);
	*potr = k;
	return (1);
}

/**
 * look_ch - Dictate chaining processe.
 * @feed: Structure denoting possibl args.
 * @buff: Buffer char subject.
 * @m: Current position buffer address.
 * @n: The start of buffer position.
 * @lngth: Curr buffer lngth.
 * Return: NULL.
 */
void look_ch(pseuarg_ch *feed, char *buff, size_t *m, size_t n, size_t lngth)
{
	size_t q = *m;

	if (feed->cdbuffertype == AND_CMND)
	{
		if (feed->tellstat)
		{
			buff[n] = 0;
			q = lngth;
		}
	}
	if (feed->cdbuffertype == OR_CMND)
	{
		if (!feed->tellstat)
		{
			buff[n] = 0;
			q = lngth;
		}
	}

	*m = q;
}

/**
 * rp_alias - Makes replacement in tokenized strs.
 * @feed: Structure denoting possible args.
 * Return: 1 succes; else 0.
 */
int rp_alias(pseuarg_ch *feed)
{
	int a;
	lst_m *sect;
	char *r;

	for (a = 0; a < 10; a++)
	{
		sect = strt_strng(feed->fake, feed->argv[0], '=');
		if (!sect)
			return (0);
		free(feed->argv[0]);
		r = str_imp(sect->strng, '=');
		if (!r)
			return (0);
		r = strngclone(r + 1);
		if (!r)
			return (0);
		feed->argv[0] = r;
	}
	return (1);
}

/**
 * rp_vstr - Makes change tokenized str.
 * @feed: Structure denoting possibl args.
 * Return: 1 success, else 0.
 */
int rp_vstr(pseuarg_ch *feed)
{
	int v = 0;
	lst_m *sect;

	for (v = 0; feed->argv[v]; v++)
	{
		if (feed->argv[v][0] != '$' || !feed->argv[v][1])
			continue;

		if (!strn_cmp(feed->argv[v], "$?"))
		{
			strn_chng(&(feed->argv[v]),
				strngclone(conv_nmber(feed->tellstat, 10, 0)));
			continue;
		}
		if (!strn_cmp(feed->argv[v], "$$"))
		{
			strn_chng(&(feed->argv[v]),
				strngclone(conv_nmber(getpid(), 10, 0)));
			continue;
		}
		sect = strt_strng(feed->exvar, &feed->argv[v][1], '=');
		if (sect)
		{
			strn_chng(&(feed->argv[v]),
				strngclone(str_imp(sect->strng, '=') + 1));
			continue;
		}
		strn_chng(&feed->argv[v], strngclone(""));

	}
	return (0);
}

/**
 * strn_chng - Responsible for replacing str subject.
 * @o_str: Address of initial str.
 * @n_str: Str subject.
 * Return: 1 success, else 0.
 */
int strn_chng(char **o_str, char *n_str)
{
	free(*o_str);
	*o_str = n_str;
	return (1);
}
