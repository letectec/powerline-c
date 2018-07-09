#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include "ansi.h"
#include "print.h"
#include "powerline.h"

static void	get_next_folder(char **cwd, char *folder)
{
	memset(folder, '\0', BUFFER_SIZE);
	if (**cwd == '\0')
	{
		folder[0] = '\0';
		return;
	}

	if (**cwd == '/')
	{
		char	*home = getenv("HOME");

		if (home != NULL && strncmp(*cwd, home, strlen(home)) == 0)
		{
			*cwd += strlen(home) + 1;
			memcpy(folder, HOME_PATTERN, 3);
			return;
		}
		(*cwd) += 1;
		strcpy(folder, "/");
		return;
	}

	unsigned int	i = 0;
	for (; **cwd != '\0' && **cwd != '/'; ++i)
	{
		folder[i] = **cwd;
		(*cwd) += 1;
	}
	if (**cwd == '/')
		(*cwd) += 1;
}

static void	choose_arrow(colors_t *colors)
{
	bool	is_full = colors->background != ansi_bg_light_gray
		|| colors->foreground != ansi_color_dark_white;

	print_arrow(colors->foreground, colors->background, is_full);
}

static void	display_directory_lock(colors_t *colors)
{
	char	cwd[BUFFER_SIZE + 1];

	getcwd(cwd, BUFFER_SIZE);
	if (access(cwd, W_OK) != 0)
	{
		colors->background = (char *)ansi_bg_red;
		if (colors->foreground == (char *)ansi_color_white)
			colors->foreground = (char *)ansi_color_light_gray;
		choose_arrow(colors);
		color_puts(ansi_color_white, ansi_bg_red, SYMBOL_LOCK);
		colors->foreground = (char *)ansi_color_red;
	}
}

static void	display_prompt(colors_t *colors, bool is_error)
{
	colors->background = (char *)(is_error ? ansi_bg_pink : ansi_bg_gray);
	choose_arrow(colors);
	color_puts(ansi_color_white, colors->background, "$");
	colors->foreground = (char *)(is_error ? ansi_color_pink : ansi_color_gray);
	colors->background = (char *)ansi_bg_reset;
	choose_arrow(colors);
}

static void	display_folders(colors_t *colors)
{
	char	*cwd = get_cwd();
	char	folder[BUFFER_SIZE + 1];

	for (get_next_folder(&cwd, folder); folder[0] != '\0'; get_next_folder(&cwd, folder))
	{
		if (memcmp(folder, HOME_PATTERN, 3) == 0)
		{
			print_home(colors);
			colors->foreground = (char *)ansi_color_cyan;
		}
		else
		{
			colors->background = (char *)ansi_bg_light_gray;
			if (colors->foreground != ansi_color_white)
				choose_arrow(colors);
			colors->foreground = (char *)(*cwd == '\0' ? ansi_color_white : ansi_color_dark_white);
			color_puts(colors->foreground, colors->background, folder);
			colors->foreground = (char *)ansi_color_light_gray;
		}
	}

}

static int	get_status(int argc, char **argv)
{
	long	status = 0;

	ASSERT_RETURN(argc > 1, 0);
	errno = 0;
	status = strtol(argv[1], NULL, 10);
	ASSERT_RETURN(errno == 0, 0);
	return ((int)(status));
}

int	main(int argc, char **argv)
{
	colors_t	colors = {(char *)ansi_bg_light_gray, (char *)ansi_color_white};
	int		status = get_status(argc, argv);

	display_folders(&colors);
	display_directory_lock(&colors);
	display_prompt(&colors, status != 0);

	reset_flush();
	return (EXIT_SUCCESS);
}