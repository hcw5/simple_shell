#include "shell.h"

/**
 * main - main func (entrypoint)
 * @ac: Argument count.
 * @av: Argument vector.
 * Return: 0 if successful , else 1 on error
 */
int main(int ac, char **av)
{
	pseuarg_ch feed[] = { INIT_GET };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				putide(av[0]);
				putide(": 0: Can't open ");
				putide(av[1]);
				charins('\n');
				charins(BUFFER_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		feed->telldes = fd;
	}
	fill_env(feed);
	rdhist(feed);
	shellmain(feed, av);
	return (EXIT_SUCCESS);
}
