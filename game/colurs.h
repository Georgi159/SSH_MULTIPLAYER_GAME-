#define ACC_BLACK		"\033[0;30m"
#define ACC_RED			"\033[0;31m"
#define ACC_GREEN		"\033[0;32m"
#define ACC_BROWN		"\033[0;33m"
#define ACC_BLUE		"\033[0;34m"
#define ACC_MAGENTA		"\033[0;35m"
#define ACC_CYAN		"\033[0;36m"
#define ACC_WHITE		"\033[0;37m"
#define ACC_LIGHTGRAY	"\033[0;38m"
#define ACC_DEFALT		"\033[0;38m"
#define ACC_RESET		"\033[0;0m"

#define ACC_BLACK_BOLD		"\033[01;30m"
#define ACC_RED_BOLD		"\033[01;31m"
#define ACC_GREEN_BOLD		"\033[01;32m"
#define ACC_BROWN_BOLD		"\033[01;33m"
#define ACC_BLUE_BOLD		"\033[01;34m"
#define ACC_MAGENTA_BOLD	"\033[01;35m"
#define ACC_CYAN_BOLD		"\033[01;36m"
#define ACC_WHITE_BOLD		"\033[01;37m"
#define ACC_LIGHTGRAY_BOLD	"\033[01;38m"




#define ACB_BLACK		"\033[7;40m"
#define ACB_RED			"\033[7;41m"
#define ACB_GREEN		"\033[7;42m"
#define ACB_BROWN		"\033[7;43m"
#define ACB_BLUE		"\033[7;44m"
#define ACB_MAGENTA		"\033[7;45m"
#define ACB_CYAN		"\033[7;46m"
#define ACB_WHITE		"\033[7;47m"
#define ACB_LIGHTGRAY	"\033[7;48m"
#define ACB_DEFALT		"\033[7;49m"
#define ACB_RESET		"\033[0m"

#define ACC_BLACK_UNDERLINE			"\033[04;30m"
#define ACC_RED_UNDERLINE			"\033[04;31m"
#define ACC_GREEN_UNDERLINE			"\033[04;32m"
#define ACC_BROWN_UNDERLINE			"\033[04;33m"
#define ACC_BLUE_UNDERLINE			"\033[04;34m"
#define ACC_MAGENTA_UNDERLINE		"\033[04;35m"
#define ACC_CYAN_UNDERLINE			"\033[04;36m"
#define ACC_WHITE_UNDERLINE			"\033[04;37m"
#define ACC_LIGHTGRAY_UNDERLINE		"\033[04;38m"
#define ACC_DEFALT_UNDERLINE		"\033[04;39m"
#define ACC_RESET_UNDERLINE			"\033[04;0m"

#define M_UP "\033[A"
#define M_DOWN "\033[B"
#define M_LEFT "\033[D"
#define M_RIGHT "\033[C"


/*033[0m - is the default color for the console
\033[0;#m - is the color of the text, where # is one of the codes mentioned above
\033[1m - makes text bold
\033[1;#m - makes colored text bold**
\033[2;#m - colors text according to # but a bit darker
\033[4;#m - colors text in # and underlines
\033[7;#m - colors the background according to #
\033[9;#m - colors text and strikes it
\033[A - moves cursor one line above (carfull: it does not erase the previously written line)
\033[B - moves cursor one line under
\033[C - moves cursor one spacing to the right
\033[D - moves cursor one spacing to the left
\033[E - don't know yet
\033[F - don't know yet


black - 30
red - 31
green - 32
brown - 33
blue - 34
CYAN - 35 CYAN
cyan - 36
lightgray - 37
*/