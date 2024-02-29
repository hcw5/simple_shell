#include "shell.h"

/**
 * cmdprt - Checks executable possibelty
 * @feed: Structure denoting possible args
 * @way: File path
 * Return: 1
 */
int cmdprt(pseuarg_ch *feed, char *way)
{
	struct stat st;

	(void)feed;
	if (!way || stat(way, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * chardup - Char duplicator
 * @stpth: Path str
 * @inds: Starting index
 * @sind: Stopping index
 * Return: Ptr
 */
char *chardup(char *stpth, int inds, int sind)
{
	int a = 0, q = 0;
	static char buff[1024];

	for (q = 0, a = inds; a < sind; a++)
		if (stpth[a] != ':')
			buff[q++] = stpth[a];
	buff[q] = 0;
	return (buff);
}

/**
 * locpath - Locates in path
 * @feed: Structure denoting possible args
 * @stpth: Path str
 * @findcmd: The located cmd
 * Return: Path
 */
char *locpath(pseuarg_ch *feed, char *stpth, char *findcmd)
{
	int a = 0, i_nitial = 0;
	char *way;

	if (!stpth)
		return (NULL);
	if ((lngth_str(findcmd) > 2) && at_strt(findcmd, "./"))
	{
		if (cmdprt(feed, findcmd))
			return (findcmd);
	}
	while (1)
	{
		if (!stpth[a] || stpth[a] == ':')
		{
			way = chardup(stpth, i_nitial, a);
			if (!*way)
				strn_cat(way, findcmd);
			else
			{
				strn_cat(way, "/");
				strn_cat(way, findcmd);
			}
			if (cmdprt(feed, way))
				return (way);
			if (!stpth[a])
				break;
			i_nitial = a;
		}
		a++;
	}
	return (NULL);
}
