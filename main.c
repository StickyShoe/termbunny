#include <sys/ioctl.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "vector.c"

int timeout() {
	struct timespec tim,rem;
	tim.tv_nsec=20000000L;
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

char bright(int val) {
	const char *brightness = " .,;oO0@";

	if (val < 0)
		return brightness[0];
	else if (val > strlen(brightness) -1 )
		return brightness[strlen(brightness) -1 ];
	return brightness[val];
}

int sqr(int i) {return i * i;}

void circle(imat2 *screen, ivec2 center, int radius, int brightness) {
	int r_sqr = sqr(radius);

	for(int y = 0; y < screen->size.y; y++) {
		for (int x = 0; x < screen->size.x; x++)
			screen->data[x][y] += brightness * ((sqr(x-center.x) + sqr(y-center.y)) < r_sqr);
	}
}

void draw(imat2 *screen) {
	for (int y = 0; y < screen->size.y; y++) {
		for (int x = 0; x < screen->size.x; x++) {
			putc(bright(screen->data[x][y]), stdout);
		}
		putc('\n', stdout);
	}
}

void main_draw(ivec2 bounds) {
	imat2 screen = newMatrix(bounds, 0);
	circle(&screen, (ivec2){20,20}, 18, 1);
	circle(&screen, (ivec2){bounds.x/2, bounds.y/2}, bounds.y/2, 1);
	circle(&screen, (ivec2){bounds.x/4, bounds.y/2 - 3}, 10, 1);
	circle(&screen, (ivec2){bounds.x - 10, bounds.y - 10}, 8, 4);
	circle(&screen, (ivec2){bounds.x/2, bounds.y/2}, bounds.y/2 - 5, 2);
	circle(&screen, (ivec2){bounds.x/2, bounds.y/2}, bounds.y/2 - 12, -3);
	clearscreen();
	draw(&screen);
}

int main(int argc, char **argv) {
	ivec2 bounds;

	for(;;) {
		ivec2 nbounds = getScreenSize();
		if (nbounds.x != bounds.x || nbounds.y != bounds.y) {
			bounds = nbounds;
			main_draw(bounds);
		}
		timeout();
	}
	return 0;
}
