/*
 sieves.c
 By Alexander Manske.
 Last modified: 2015-09-18
 Using some code of print_prime.c	
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
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

void print_sieves(int n){
	int sievelist[n]; //allocating on the stack
	int i; //index
	int j; //index
	for (i = 2; i < n; i++){ //set the array to true (1) from index 2 to n
		sievelist[i] = 1;
	}

	/* if we found one true index, set all multiples of that to false (0)*/
	for (i = 2; i*i < n; i++){ //i*i instead of sqrt(n)
		if(sievelist[i]){
			for(j = i*i; j < n; j += i){ 
				sievelist[j] = 0; //false
				
			}
		}
	}
	for (i = 2; i < n; i++){ //for all true indices, print that number
		if(sievelist[i]){
			print_number(i);
		}
	}
	printf("\n");
}



// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
  if(argc == 2)
    print_sieves(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
  return 0;
}