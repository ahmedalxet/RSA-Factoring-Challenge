#include <stdio.h>

int main(int argc, char *argv[])
{
	// Get the input file name from the command line
	char *input_file = argv[1];

	// Open the input file
	FILE *f = fopen(input_file, "r");

	// Read the numbers from the file, one per line
	int n;
	while (fscanf(f, "%d", &n) == 1) {
		// Initialize p and q to n
		int p = n;
		int q = n;

		// Try all possible values for p, starting with 2 and going up to n-1
		for (int i = 2; i < n; i++) {
			// If n is divisible by i, set p to i and q to n/i
			if (n % i == 0) {
				p = i;
				q = n / i;
				break;
			}
		}

		// Print the result
		printf("%d=%d*%d\n", n, p, q);
	}

	// Close the input file
	fclose(f);

	return 0;
}
