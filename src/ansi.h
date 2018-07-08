#pragma once

#define ANSI_RESET		"\e[0m"

#define ANSI_COLOR_WHITE	"\e[38;5;254m"
#define ANSI_COLOR_RED		"\e[38;5;124m"
#define ANSI_COLOR_PINK		"\e[38;5;161m"
#define ANSI_COLOR_DARK_WHITE	"\e[38;5;250m"
#define ANSI_COLOR_CYAN		"\e[38;5;31m"
#define ANSI_COLOR_LIGHTER_GRAY	"\e[38;5;244m"
#define ANSI_COLOR_LIGHT_GRAY	"\e[38;5;237m"
#define ANSI_COLOR_GRAY		"\e[38;5;236m"
#define ANSI_COLOR_RESET	"\e[39m"

#define ANSI_BG_CYAN		"\e[48;5;31m"
#define ANSI_BG_PINK		"\e[48;5;161m"
#define ANSI_BG_RED		"\e[48;5;124m"
#define ANSI_BG_LIGHT_GRAY	"\e[48;5;237m"
#define ANSI_BG_GRAY		"\e[48;5;236m"
#define ANSI_BG_RESET		"\e[49m"

#define SYMBOL_LOCK		"\uE0A2"
#define SYMBOL_FULL_ARROW	"\uE0B0"
#define SYMBOL_LIGHT_ARROW	"\uE0B1"
#define SYMBOL_HOME		"~"

extern const char	ansi_reset[];

extern const char	ansi_color_white[];
extern const char	ansi_color_red[];
extern const char	ansi_color_pink[];
extern const char	ansi_color_dark_white[];
extern const char	ansi_color_cyan[];
extern const char	ansi_color_lighter_gray[];
extern const char	ansi_color_light_gray[];
extern const char	ansi_color_gray[];
extern const char	ansi_color_reset[];

extern const char	ansi_bg_cyan[];
extern const char	ansi_bg_pink[];
extern const char	ansi_bg_red[];
extern const char	ansi_bg_light_gray[];
extern const char	ansi_bg_gray[];
extern const char	ansi_bg_reset[];