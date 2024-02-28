#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

extern char **environ;

#define CONVERT_LOWER	1
#define CONVERT_UNINT	2

#define NORMAL_CMND	0
#define OR_CMND		1
#define AND_CMND	2
#define CHAIN_CMND	3

#define READ_BUFFER_SIZE 1024
#define WRITE_BUFFER_SIZE 1024
#define BUFFER_FLUSH -1

#define FOR_STRTOK 0
#define FOR_GETLINE 0

#define FILE_H	".simple_shell_history"
#define MAX_H	4096

/**
 * struct strng_l - A singly linked list
 * @nmber: The field denoting numbers
 * @strng: The string
 * @next: The pointer to the next node
 */
typedef struct strng_l
{
	int nmber;
	char *strng;
	struct strng_l *next;
}	lst_m;

/**
 *struct pseuarg - The pseudo-arguements to be passed to functions
 *@arg: Argument string
 *@argv: String array
 *@way: The string path denoting the current command
 *@argc: Argument count
 *@cnterr: Error count
 *@errn: Error code
 *@cntline_flg: Input line count
 *@progname: Filename denoting the program
 *@exvar: Linked list copy
 *@environ: //Ask about this one as well
 *@hst: Node denoting the history
 *@fake: Node denoting the alias
 *@new_env: Checks for environment change
 *@tellstat: Return status of previous command
 *@cdbuffer: Pointer address
 *@cdbuffertype: CMD_type ||, &&, ; //Hapa roho safi sijui
 *@telldes: Fd denoting line input
 *@tellhist: Number of history lines
 */
typedef struct pseuarg
{
	char *arg;
	char **argv;
	char *way;
	int argc;
	unsigned int cnterr;
	int errn;
	int cntline_flg;
	char *progname;
	lst_m *exvar;
	lst_m *hst;
	lst_m *fake;
	char **environ;
	int new_env;
	int tellstat;

	char **cdbuffer;
	int cdbuffertype;
	int telldes;
	int tellhist;
}	pseuarg_ch;

#define INIT_GET \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct embedstr - Struct contains embedded str and respective fn.
 *@cflg: The flag denoting the embedded command
 *@resfunc: The respective function
 */
typedef struct embedstr
{
	char *cflg;
	int (*resfunc)(pseuarg_ch *);
}	embed_str;

int shelloop(char **);

/* shcirc.c */
int shellmain(pseuarg_ch *, char **);
int go_emb(pseuarg_ch *);
void loc_comm(pseuarg_ch *);
void loc_fork(pseuarg_ch *);

/* strngf.c */
char *strngcop(char *, char *);
char *strngclone(const char *);
void strngin(char *);
int _putchar(char);

/* split.c */
int cmdprt(pseuarg_ch *, char *);
char *chardup(char *, int, int);
char *locpath(pseuarg_ch *, char *, char *);

/* err.c */
void putide(char *);
int charins(char);
int fputer(char c, int fd);
int fndpt(char *strng, int fd);

/* exout.c */
char *cppy_strng(char *, char *, int);
char *strngmod(char *, char *, int);
char *str_imp(char *, char);

/* strng.c */
int lngth_str(char *);
int strn_cmp(char *, char *);
char *at_strt(const char *, const char *);
char *strn_cat(char *, char *);

/* errf.c */
int exst_err(char *);
void errorprnt(pseuarg_ch *, char *);
int disprnt(int, int);
char *conv_nmber(long int, int, int);
void rm_comm(char *);

/* rloc.c */
char *mmry_arn(char *, char, unsigned int);
void dmfree(char **);
void *mem_ralloc(void *, unsigned int, unsigned int);

/* linget.c */
ssize_t inpt_gt(pseuarg_ch *);
int get_delim(pseuarg_ch *, char **, size_t *);
void mngint(int);

/* reward.c */
char **mod_strng(char *, char *);
char **checkstrn(char *, char);

/* rem.c */
int mem_free(void **);

/* iget.c */
void infclr(pseuarg_ch *);
void infprs(pseuarg_ch *, char **);
void infree(pseuarg_ch *, int);

/* eget.c */
char **aqrenv(pseuarg_ch *);
int envunp(pseuarg_ch *, char *);
int ptenv(pseuarg_ch *, char *, char *);

/* at.c */
int actv_int(pseuarg_ch *);
int prser(char, char *);
int bst_int(int);
int genint(char *);

/* evar.c */
char *pop_env(pseuarg_ch *, const char *);
int myown_env(pseuarg_ch *);
int good_env(pseuarg_ch *);
int bad_env(pseuarg_ch *);
int fill_env(pseuarg_ch *);

/* lstf.c */
size_t lngth_lst(const lst_m *);
char **strng_lst(lst_m *);
size_t prnt_lst(const lst_m *);
lst_m *strt_strng(lst_m *, char *, char);
ssize_t indx_gt(lst_m *, lst_m *);

/* blt1.c */
int hist_rep(pseuarg_ch *);
int alum_hist(pseuarg_ch *);

/* hst.c */
char *histfile_fetch(pseuarg_ch *feed);
int hist_updt(pseuarg_ch *feed);
int rdhist(pseuarg_ch *feed);
int histlst_b(pseuarg_ch *feed, char *buff, int linecount);
int nmber_hist(pseuarg_ch *feed);

/* store.c */
int str_ch(pseuarg_ch *, char *, size_t *);
void look_ch(pseuarg_ch *, char *, size_t *, size_t, size_t);
int rp_alias(pseuarg_ch *);
int rp_vstr(pseuarg_ch *);
int strn_chng(char **, char *);

/* blt.c */
int exist_sts(pseuarg_ch *);
int cd_mine(pseuarg_ch *);
int help_inf(pseuarg_ch *);

/* lst.c */
lst_m *populate_node(lst_m **, const char *, int);
lst_m *endnode_add(lst_m **, const char *, int);
size_t lststr_prnt(const lst_m *);
int indxnode_del(lst_m **, unsigned int);
void freelst(lst_m **);

#endif
