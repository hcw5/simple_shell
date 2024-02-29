#include "shell.h"

/**
 * bfer_inpt - buffrs cmds in subject.
 * @feed: Structure denoting possible arguments.
 * @buff: Buffer address in subject.
 * @leng: Length var address.
 * Return: Number of bytes present.
 */
ssize_t bfer_inpt(pseuarg_ch *feed, char **buff, size_t *leng)
{
	ssize_t w = 0;
	size_t en_lnth = 0;

	if (!*leng)
	{
		free(*buff);
		*buff = NULL;
		signal(SIGINT, mngint);
#if FOR_GETLINE
		w = getline(buff, &en_lnth, stdin);
#else
		w = get_delim(feed, buff, &en_lnth);
#endif
		if (w > 0)
		{
			if ((*buff)[w - 1] == '\n')
			{
				(*buff)[w - 1] = '\0';
				w--;
			}
			feed->cntline_flg = 1;
			rm_comm(*buff);
			histlst_b(feed, *buff, feed->tellhist++);
			{
				*leng = w;
				feed->cdbuffer = buff;
			}
		}
	}
	return (w);
}

/**
 * inpt_gt - Generates line without newline.
 * @feed: Structure denoting possible arguments
 * Return: Total number bytes.
 */
ssize_t inpt_gt(pseuarg_ch *feed)
{
	static char *buff;
	static size_t f, g, leng;
	ssize_t h = 0;
	char **bf_ptr = &(feed->arg), *q;

	_putchar(BUFFER_FLUSH);
	h = bfer_inpt(feed, &buff, &leng);
	if (h == -1)
		return (-1);
	if (leng)
	{
		g = f;
		q = buff + f;

		look_ch(feed, buff, &g, f, leng);
		while (g < leng)
		{
			if (str_ch(feed, buff, &g))
				break;
			g++;
		}

		f = g + 1;
		if (f >= leng)
		{
			f = leng = 0;
			feed->cdbuffertype = NORMAL_CMND;
		}

		*bf_ptr = q;
		return (lngth_str(q));
	}

	*bf_ptr = buff;
	return (h);
}

/**
 * rd_buf - read buffer in subjct.
 * @feed: Structure denoting possible arguments.
 * @buff: Buffer in subject.
 * @si: Demonstrates size.
 * Return: Val.
 */
ssize_t rd_buf(pseuarg_ch *feed, char *buff, size_t *si)
{
	ssize_t h = 0;

	if (*si)
		return (0);
	h = read(feed->telldes, buff, READ_BUFFER_SIZE);
	if (h >= 0)
		*si = h;
	return (h);
}

/**
 * get_delim - optain next input line from stdout.
 * @feed: Structure denoting possible arguments.
 * @ptrr: Pointer to buffer.
 * @llength: Pointer buff size after allocation.
 * Return: Val
 */
int get_delim(pseuarg_ch *feed, char **ptrr, size_t *llength)
{
	static char buff[READ_BUFFER_SIZE];
	static size_t m, leng;
	size_t n;
	ssize_t q = 0, d = 0;
	char *t = NULL, *new_pt = NULL, *a;

	t = *ptrr;
	if (t && llength)
		d = *llength;
	if (m == leng)
		m = leng = 0;

	q = rd_buf(feed, buff, &leng);
	if (q == -1 || (q == 0 && leng == 0))
		return (-1);

	a = str_imp(buff + m, '\n');
	n = a ? 1 + (unsigned int)(a - buff) : leng;
	new_pt = mem_ralloc(t, d, d ? d + n : n + 1);
	if (!new_pt)
		return (t ? free(t), -1 : -1);

	if (d)
		strngmod(new_pt, buff + m, n - m);
	else
		cppy_strng(new_pt, buff + m, n - m + 1);

	d += n - m;
	m = n;
	t = new_pt;

	if (llength)
		*llength = d;
	*ptrr = t;
	return (d);
}

/**
 * mngint - This function blocks control C shortcut.
 * @sigid: Number of signal in question.
 * Return: NULL.
 */
void mngint(__attribute__((unused))int sigid)
{
	strngin("\n");
	strngin("$ ");
	_putchar(BUFFER_FLUSH);
}
