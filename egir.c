#include "shell.h"

/**
 * putide - Print input str
 * @strng: Denotes str to printed
 * Return: Void
*/
void putide(char *strng)
{
	int n = 0;

	if (!strng)
		return;
	while (strng[n] != '\0')
	{
		charins(strng[n]);
		n++;
	}
}

/**
 * charins - Print char c
 * @charinp: Character to printed
 * Return: 1 success, -1 error
 */
int charins(char charinp)
{
	static int n;
	static char buff[WRITE_BUFFER_SIZE];

	if (charinp == BUFFER_FLUSH || n >= WRITE_BUFFER_SIZE)
	{
		write(2, buff, n);
		n = 0;
	}
	if (charinp != BUFFER_FLUSH)
		buff[n++] = charinp;
	return (1);
}

/**
 * fputer - Print char c to file descriptor
 * @charinp: Char printed
 * @fd: File descriptor
 * Return: 1 if success, -1 if error
 */
int fputer(char charinp, int fd)
{
	static int n;
	static char buff[WRITE_BUFFER_SIZE];

	if (charinp == BUFFER_FLUSH || n >= WRITE_BUFFER_SIZE)
	{
		write(fd, buff, n);
		n = 0;
	}
	if (charinp != BUFFER_FLUSH)
		buff[n++] = charinp;
	return (1);
}

/**
 * fndpt - Print input str
 * @strng: Printed str
 * @fd: File descriptor question
 * Return: Char count
 */
int fndpt(char *strng, int fd)
{
	int n = 0;

	if (!strng)
		return (0);
	while (*strng)
	{
		n += fputer(*strng++, fd);
	}
	return (n);
}
