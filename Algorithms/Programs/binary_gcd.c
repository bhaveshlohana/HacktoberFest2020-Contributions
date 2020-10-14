#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned int gcd(unsigned int u, unsigned int v) {
	unsigned int shift = 0;

	if (u == 0)
		return v;
	if (v == 0)
		return u;

	while (((u | v) & 1) == 0) {
		shift++;
		u >>= 1;
		v >>= 1;
	}

	while ((u & 1) == 0)
		u >>= 1;

	do {
		while ((v & 1) == 0)
			v >>= 1;

		if (u > v) {
			unsigned int t = v;
			v			   = u;
			u			   = t;
		}

		v -= u;
	} while (v != 0);

	return u << shift;
}

int main(int argc, char *argv[]) {
	if (argc == 3) {
		int a = atoi(argv[1]);
		int b = atoi(argv[2]);
		if (a < 0 || b < 0) {
			printf("Cannot compute gcd of non-negative values\n");
			return 1;
		}
		printf("%u\n", gcd(a, b));
	}
	if (argc > 3) {
		printf("Invalid format, more than recquired agruments given\n");
		printf("format: output_file_name number_1 number_2\n");
	}
	if (argc < 3) {
		printf("Very few agruments given\n");
		printf("format: output_file_name number_1 number_2\n");
	}
	return 0;
}
