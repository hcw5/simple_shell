#include "shell.h"

/**
 * infclr - func that activates pseuarg_ch structure.
 * @feed: Structure denoting possible arguments
 */
void infclr(pseuarg_ch *feed)
{
	feed->arg = NULL;
	feed->argv = NULL;
	feed->way = NULL;
	feed->argc = 0;
}

/**
 * infprs - activate pseuarg_ch struct.
 * @feed: Structure denoting possible arguments
 * @arv: The arg vector.
 */
void infprs(pseuarg_ch *feed, char **arv)
{
	int z = 0;

	feed->progname = arv[0];
	if (feed->arg)
	{
		feed->argv = mod_strng(feed->arg, " \t");
		if (!feed->argv)
		{

			feed->argv = malloc(sizeof(char *) * 2);
			if (feed->argv)
			{
				feed->argv[0] = strngclone(feed->arg);
				feed->argv[1] = NULL;
			}
		}
		for (z = 0; feed->argv && feed->argv[z]; z++)
			;
		feed->argc = z;

		rp_alias(feed);
		rp_vstr(feed);
	}
}

/**
 * infree - function to liberates pseuarg_ch struct fields.
 * @feed: Structure denoting possible arguments
 * @fldall: Denotes liberation of fields
 */
void infree(pseuarg_ch *feed, int fldall)
{
	dmfree(feed->argv);
	feed->argv = NULL;
	feed->way = NULL;
	if (fldall)
	{
		if (!feed->cdbuffer)
			free(feed->arg);
		if (feed->exvar)
			freelst(&(feed->exvar));
		if (feed->hst)
			freelst(&(feed->hst));
		if (feed->fake)
			freelst(&(feed->fake));
		dmfree(feed->environ);
			feed->environ = NULL;
		mem_free((void **)feed->cdbuffer);
		if (feed->telldes > 2)
			close(feed->telldes);
		_putchar(BUFFER_FLUSH);
	}
}
