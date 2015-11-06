/*
 prime.c
 By David Broman.
 Last modified: 2015-09-16
 This file is in the public domain.
 Edited by Fredrik Liljedahl

*/


#include <stdio.h>

int is_prime(int n){
	int i;
	if(n == 1) return 0; //Basecase
	if(n%2 == 0 && n != 2) return 0; // primenumbers can't be even after the number 2
	for(i = 3; i <= n/2; i+=2){ // Modulo on uneven numbers starting from 3 to n/2 
		if(n%i == 0) return 0; // Returns 0 if divisible by i 
	}
	return 1; // if it cant be divided in the loop it has to be a primenumber
}

int main(void){
	printf("%d\n", is_prime(11));  // 11 is a prime.      Should print 1.
	printf("%d\n", is_prime(383)); // 383 is a prime.     Should print 1.
	printf("%d\n", is_prime(987)); // 987 is not a prime. Should print 0.
}
