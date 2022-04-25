#include <stdio.h>

#define SIZE 100
#define ITERNO 45

char chars[] = " .:-=+*$%@";
int grid[SIZE][SIZE];

int test(float a, float b) {
	// test whether f_c(z) = z^2+c diverges or converges
	int i = 0;
	float oa = a;
	float ob = b;
	while (i < ITERNO) {
		float at = (a * a) - (b * b);
		float bt = 2 * a * b;
		a = at + oa;
		b = bt + ob;
		if (a + b > 16) break;
		i ++;
	}
	return i;
}

void render() {
	// print the contents of the grid array to the screen using the characters sorted by brightness
	for (int i = 0; i < SIZE; i ++) {
		for (int j = 0; j < SIZE; j ++) {
			int p = grid[i][j];
			printf("%c", chars[p]);
		}
		printf("\n");
	}	
}

float mapTo(float n, float a, float b, float c, float d) {
	// map a number from one range to another
	return c + ((d - c) / (b - a)) * (n - a);
}

int main() {
	for (int y = 0; y < SIZE; y ++) {
		for (int x = 0; x < SIZE; x ++) {
			float mx = mapTo(x, 0, SIZE, -2, 2);
			float my = mapTo(y, 0, SIZE, -2, 2);
			int pt = mapTo(test(mx, my), 0, ITERNO, 0, 9);
			grid[y][x] = pt;
		}
	}
	render();
}