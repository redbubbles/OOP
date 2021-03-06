// OOP_Task1_PrimeNumbers.cpp : Defines the entry point for the console application.
//

/*1. a. Generate all the prime numbers smaller than a given natural number n.
	 b. Given a vector of numbers, find the longest increasing contiguous subsequence, such the sum
of that any 2 consecutive elements is a prime number.

*/

#include "stdafx.h"
#include "stdio.h"
#include "math.h"

int isPrime(int x) {
	if ((x % 2 == 0 && x > 2) || x < 2)
		return 0;
	int d = 3;
	for (; d*d <= x; d += 2)
		if (x%d == 0)
			return 0;
	return 1;
}

void longestSequence(int seq[100], int n) {
	int s_pos = 0, s_length = 0, l = 0, pos = 0, prev_prim = 0;
	for (int i = 0; i < n - 1; i++) {
		if (!isPrime(seq[i] + seq[i + 1])) {
			if (prev_prim = 1)
				l++;
			if (s_length <= l) {
				s_length = l;
				s_pos = pos;
			}
			l = 0;
		}
		else {
			if (l == 0)
				pos = i;
			l++;
			prev_prim = 1;
		}
	}
	for (int i = s_pos; i < s_length; i++)
		printf_s("%d, ", seq[i]);
}


int main()
{
	int n;
	printf_s("Please insert a number:");
	scanf_s("%d", &n);

	printf("\nAll the prime numbers smaller than %d are: ", n);
	int x = 0; 
	while (x < n) {
		if (isPrime(x))
			printf_s("%d, ", x);
		x++;
	}

	printf_s("\nPlease insert a the numbers of elements in vector: ");
	scanf_s("%d", &n);
	x = 0;	
	int seq[100];
	printf_s("\n Please insert the elements of the vector:");
	while (x < n) {
		scanf_s("%d\n", &seq[x]);
		x++;
	}

	longestSequence(seq, n);

    return 0;
}