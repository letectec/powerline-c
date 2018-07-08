#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "ansi.h"
#include "powerline.h"

void	reset_flush()
{
	fputs(ansi_reset, stdout);
	putchar(' ');
	fflush(stdout);
}

char	*xstrdup(const char *string)
{
	return (string == NULL ? NULL : strdup(string));
}

char	*get_cwd()
{
	char	cwd[BUFFER_SIZE + 1];

	getcwd(cwd, BUFFER_SIZE);
	return (xstrdup(cwd));
}