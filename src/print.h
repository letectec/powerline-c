#pragma once

#include "powerline.h"

void	color_puts(const char *text_color, const char *bg_color, const char *string);
void	color_put_symbol(const char *text_color, const char *bg_color, const char *symbol);
void	print_arrow(const char *arrow_color, const char *bg_color, bool is_full);
void	print_home(colors_t *colors);