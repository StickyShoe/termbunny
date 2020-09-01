#include <stdlib.h>
#include <stdio.h>

typedef struct { int x; int y; } ivec2;
typedef struct { ivec2 size; int** data; } imat2;

void initializeMatrix(imat2 *mat, int value) {
	for(int x = 0; x < mat->size.x; x++) {
		for (int y = 0; y < mat->size.y; y++)
			mat->data[x][y] = value;
	}
}

imat2 newMatrix(ivec2 size, int init) {
	imat2 out;
	out.size = size;
	out.data = (int**) malloc(sizeof(int*) * size.x);
	for (int x = 0; x < size.x; x++)
		out.data[x] = (int*) malloc(sizeof(int) * size.y);
	initializeMatrix(&out, init);
	return out;
}

void printMatrix(imat2 *mat) {
	for(int x = 0; x < mat->size.x; x++) {
		for (int y = 0; y < mat->size.y - 1; y++)
			fprintf(stdout, "%i, ", mat->data[x][y]);
		fprintf(stdout, "%i\n", mat->data[x][mat->size.y - 1]);
	}
}

