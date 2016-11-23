#include<stdio.h>

void print_menu();
int gcd(int, int);
void subtask_1();
void subtask_2();
int get_sequence_of_coprimes(int*, int);
int get_longest_sequence_maximum_sum(int*, int, int*);

int main() {
	/* Main function.
	 * Input: none
	 * Output: none */

	int option;

	while (1) {
		print_menu();
		scanf("%d", &option);

		if (option == 1)
			subtask_1();
		else if (option == 2)
			subtask_2();
		else if (option == 0)
			break;
		else
			printf("Invalid option!\n");
	}

	return 0;
}

void print_menu() {
	/* Prints the console-based menu of the program.
	 * Input: none
	 * Output: none */

	printf("Pick an option:\n");
	printf(
			"1 - Determine all the numbers smaller than a given natural and non-null number n and that are relatively prime to n.\n");
	printf(
			"2 - Given a vector of numbers, find the longest contiguous subsequence with the maximum sum.\n");
	printf("0 - Exit\n");
}

int gcd(int a, int b) {
	/* Computes the greatest common divisor of two natural numbers.
	 * Input: a - natural number
	 * 		  b - natural number
	 * Output: natural number - greatest common divisor of a and b */

	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void subtask_1() {
	/* Solves the first task.
	 * Input: none
	 * Output: none */

	int n, length_of_sequence, i;
	int sequence_of_coprimes[101];

	do {
		printf("Read natural and non-null number n (max. 100): ");
		scanf("%d", &n);
	} while (n <= 0 || n > 100);

	length_of_sequence = get_sequence_of_coprimes(sequence_of_coprimes, n);

	if (!length_of_sequence)
		printf("No numbers found.\n");
	else {
		printf("We found: ");
		for (i = 0; i < length_of_sequence; i++)
			printf("%d ", sequence_of_coprimes[i]);
		printf("\n");
	}
}

int get_sequence_of_coprimes(int *sequence_of_coprimes, int n) {
	/* Computes a sequence of numbers coprime with a given one.
	 * Input: sequence_of_coprimes - pointer to an array of integers where solution will be stored
	 *        n - natural and non-null number to generate sequence of coprimes
	 * Output: natural number - length of the sequence of coprimes */

	int i, length_of_sequence = 0;
	for (i = 1; i < n; i++)
		if (gcd(i, n) == 1)
			sequence_of_coprimes[length_of_sequence++] = i;
	return length_of_sequence;
}

void subtask_2() {
	/* Solves the second task.
	 * Input: none
	 * Output: none */

	int n, length_of_final_sequence, i;
	int initial_sequence[101];
	int final_sequence[101];

	do {
		printf("Read number of elements (max. 100): ");
		scanf("%d", &n);
	} while (n <= 0 || n > 100);

	printf("Read %d numbers: ", n);
	for (i = 0; i < n; i++)
		scanf("%d", &initial_sequence[i]);

	length_of_final_sequence = get_longest_sequence_maximum_sum(
			initial_sequence, n, final_sequence);

	printf("We found: ");

	for (i = 0; i < length_of_final_sequence; i++)
		printf("%d ", final_sequence[i]);

	printf("\n");
}

int get_longest_sequence_maximum_sum(int *initial_sequence, int n,
		int *final_sequence) {
	/* Computes the longest sequence with the maximum sum of a given sequence.
	 * Input: initial_sequence - pointer to an array of integers
	 *        n - integer representing the length of the initial_sequence
	 *        final_sequence - pointer to array of integers where the l.s.m.s. will be stored
	 * Output: natural number - length of the longest sequence with maximum sum */

	int i, j, k;
	int maxsum = initial_sequence[0];
	int besti = 0, bestj = 0;

	for (i = 0; i < n; i++)
		for (j = i; j < n; j++) {
			int sum = 0;

			for (k = i; k <= j; k++)
				sum += initial_sequence[k];

			if (sum > maxsum) {
				maxsum = sum;
				besti = i;
				bestj = j;
			}

			if (sum == maxsum && bestj - besti < j - i) {
				besti = i;
				bestj = j;

			}
		}

	for (i = besti; i <= bestj; i++)
		final_sequence[i - besti] = initial_sequence[i];

	return bestj - besti + 1;
}
