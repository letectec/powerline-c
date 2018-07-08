#pragma once

#define	BUFFER_SIZE	1024	// terminal can hold at most 200 columns so
				// we should be fine

#define HOME_PATTERN	"~\0~"	// out of bounds of a null terminated string
				// if it's really a home and not a "~" folder

#define ASSERT_RETURN(x, y)	if (!(x)) return (y);

typedef struct
{
	char	*background;
	char	*foreground;
}	colors_t;

void	reset_flush();
char	*xstrdup(const char *string);
char	*get_cwd();