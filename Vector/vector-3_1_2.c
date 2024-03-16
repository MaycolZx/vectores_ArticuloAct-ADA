#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int* gpVect = NULL;
int gnCount = 0;
int gnMax = 0;

void Insert(int elem) {
	if (gnCount == gnMax)
		Resize();
	gpVect[gnCount++] = elem;
}

void Resize() {
	const int delta = 10;
	gpVect = realloc(gpVect, sizeof(int) * (gnMax + delta));
	gnMax += delta;
}

int main() {
	return 0;
}