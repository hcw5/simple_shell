#include "shell.h"

/**
 * exist_sts - exit shell cmd.
 * @feed: Structure containing constant function prototype.
 * Return: Respective exit status.
 */
int exist_sts(pseuarg_ch *feed)
{
	int ext_stat;

	if (feed->argv[1])
	{
		ext_stat = exst_err(feed->argv[1]);
		if (ext_stat == -1)
		{
			feed->tellstat = 2;
			errorprnt(feed, "Illegal number: ");
			putide(feed->argv[1]);
			charins('\n');
			return (1);
		}
		feed->errn = exst_err(feed->argv[1]);
		return (-2);
	}
	feed->errn = -1;
	return (-2);
}

/**
 * cd_mine - Shifts the current Process directory.
 * @feed: Structure denoting potential fn prototype.
 * Return: 0.
 */
int cd_mine(pseuarg_ch *feed)
{
	char *sst, *directry, buffer[1024];
	int retchld;

	sst = getcwd(buffer, 1024);
	if (!sst)
		strngin("TODO: >>getcwd failure emsg here<<\n");
	if (!feed->argv[1])
	{
		directry = pop_env(feed, "HOME=");
		if (!directry)
			retchld =
				chdir((directry = pop_env(feed, "PWD=")) ? directry : "/");
		else
			retchld = chdir(directry);
	}
	else if (strn_cmp(feed->argv[1], "-") == 0)
	{
		if (!pop_env(feed, "OLDPWD="))
		{
			strngin(sst);
			_putchar('\n');
			return (1);
		}
		strngin(pop_env(feed, "OLDPWD=")), _putchar('\n');
		retchld =
			chdir((directry = pop_env(feed, "OLDPWD=")) ? directry : "/");
	}
	else
		retchld = chdir(feed->argv[1]);
	if (retchld == -1)
	{
		errorprnt(feed, "can't cd to ");
		putide(feed->argv[1]), charins('\n');
	}
	else
	{
		ptenv(feed, "OLDPWD", pop_env(feed, "PWD="));
		ptenv(feed, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * help_inf - Change dir (cd).
 * @feed: Structure containing potential fn prototype.
 * Return: 0.
 */
int help_inf(pseuarg_ch *feed)
{
	char **arr_arg;

	arr_arg = feed->argv;
	strngin("help call works. Function not yet implemented \n");
	if (0)
		strngin(*arr_arg);
	return (0);
}
