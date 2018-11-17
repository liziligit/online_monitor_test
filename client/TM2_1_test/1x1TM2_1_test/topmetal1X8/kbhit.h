#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <termios.h>
#include <termio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <errno.h>
#include <regex.h>
#include <sys/time.h>

using namespace std;
static struct termio term_orig;
static int kbdflgs;
/* 判断是否有按键按下 */
int kbhit(void)
{
	struct timeval tv;
	struct termios old_termios, new_termios;
	int error;
	int count = 0;
	tcgetattr(0, &old_termios);
	new_termios = old_termios;
	new_termios.c_lflag &= ~ICANON;
	new_termios.c_lflag &= ~ECHO;
	new_termios.c_cc[VMIN] = 1;
	new_termios.c_cc[VTIME] = 0;
	error = tcsetattr(0, TCSANOW, &new_termios);
	tv.tv_sec = 0;
	tv.tv_usec = 100;
	select(1, NULL, NULL, NULL, &tv);
	error += ioctl(0, FIONREAD, &count);
	error += tcsetattr(0, TCSANOW, &old_termios);
	return error == 0 ? count : -1;
}

/**
* system_mode
* reset the system to what it was before input_mode was
* called
*/
void system_mode(void)
{
	if (ioctl(0, TCSETA, &term_orig) == -1) {
		return;
	}
	fcntl(0, F_SETFL, kbdflgs);
}
/**
* input_mode
* set the system into raw mode for keyboard i/o
* returns  0 - error
*          1 - no error
*/
int input_mode(void)
{
	struct termio term;
	if (ioctl(0, TCGETA, &term) == -1) {
		return 0;
	}

	(void)ioctl(0, TCGETA, &term_orig);
	term.c_iflag = 0;
	term.c_oflag = 0;
	term.c_lflag = 0;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (ioctl(0, TCSETA, &term) == -1) {
		return 0;
	}
	kbdflgs = fcntl(0, F_GETFL, 0);
	int flags = fcntl(0, F_GETFL);
	flags &= ~O_NDELAY;
	fcntl(0, F_SETFL, flags);
	return 1;
}

/**
* getch
* read a single character from the keyboard without echo
* returns: the keypress character
*/
int getch(void)
{
	unsigned char ch;
	input_mode();
	while (read(0, &ch, 1) != 1);
	system_mode();
	return (ch);
}


