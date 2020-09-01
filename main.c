#include <sys/ioctl.h>
#include <stdio.h>
#include <time.h>
#include "vector.c"

int timeout() {
	struct timespec tim,rem;
	tim.tv_nsec=500000000L;
	tim.tv_sec=0;
	nanosleep(&tim,&rem);
	return 0;	
}

int clearscreen() {
	printf("\e[1;1H\e[2J");
	return 0;
}

ivec2 getScreenSize(){
	struct winsize sz;
	ioctl(0, TIOCGWINSZ, &sz);

	ivec2 out;
	out.x = sz.ws_col;
	out.y = sz.ws_row;

	return out;
}

int main(int argc, char **argv) {

	ivec2 bounds = getScreenSize();

	printf("Screen width: %i  Screen height: %i\n", bounds.x, bounds.y);
	imat2 screen = newMatrix(bounds, 0);
	printMatrix(&screen);
	return 0;
}
