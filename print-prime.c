/*
 print-prime.c
 By David Broman.
 Last modified: 2015-09-16
 This file is in the public domain.
 Edited by Alexander Manske
*/


#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6

int column = 1; //starting column

void print_number(int n){
  if(column == COLUMNS) { //If we have reached the end column
    printf("%d\n", n); //print n and then a new line
    column = 1;  //reset column counter
  }else{
    printf("%d\t", n); //print n and a tab
    column++; //increment column
  }
}

void print_primes(int n){
  int i;
  for(i = 1; i <= n; i++){ //loop through all positive numbers up to n
    if(is_prime(i)){ //check if prime
      print_number(i); //print the number
    }
  }
  printf("\n"); //print a new line at the end of the program
}
/*
 Part of prime.c
 By David Broman.
 Last modified: 2015-09-16
 This file is in the public domain.
 Edited by Fredrik Liljedahl

*/

int is_prime(int n){
  int i;
  if(n == 1) return 0; //Basecase
  if(n%2 == 0 && n != 2) return 0; // primenumbers can't be even after the number 2
  for(i = 3; i <= n/2; i+=2){ // Modulo on uneven numbers starting from 3 to n/2 
    if(n%i == 0) return 0; // Returns 0 if divisible by i 
  }
  return 1; // if it cant be divided in the loop it has to be a primenumber
}

// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
  if(argc == 2)
    print_primes(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
  return 0;
}



