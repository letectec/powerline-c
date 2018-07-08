#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "ansi.h"
#include "powerline.h"

void	color_puts(const char *text_color, const char *bg_color, const char *string)
{
	printf("%s%s %s ", text_color, bg_color, string);
}

void	color_put_symbol(const char *text_color, const char *bg_color, const char *symbol)
{
	printf("%s%s%s", text_color, bg_color, symbol);
}

void	print_home(colors_t *colors)
{
	color_puts(ANSI_COLOR_WHITE, ANSI_BG_CYAN, SYMBOL_HOME);
	colors->background = (char *)ansi_bg_cyan;
	colors->foreground = (char *)ansi_color_white;
}

void	print_arrow(const char *arrow_color, const char *bg_color, bool is_full)
{
	if (is_full)
		color_put_symbol(arrow_color, bg_color, SYMBOL_FULL_ARROW);
	else
		color_put_symbol(ansi_color_lighter_gray, bg_color, SYMBOL_LIGHT_ARROW);
}