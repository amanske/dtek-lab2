//Edited by Fredrik Liljedahl, fri 18 sep 2015


#include <stdio.h>
#include <stdlib.h>
char* text1 = "This is a string.";
char* text2 = "Yet another thing.";
//int* list1;
//int* list2;
int list1[20]; //declaring lists with sizes of 20 integers
int list2[20];
int count = 0; 


void printlist(const int* lst){
  printf("ASCII codes and corresponding characters.\n");
  while(*lst != 0){
    printf("0x%03X '%c' ", *lst, (char)*lst);
    lst++;
  }
  printf("\n");
}

void endian_proof(const char* c){
  printf("\nEndian experiment: 0x%02x,0x%02x,0x%02x,0x%02x\n", 
         (int)*c,(int)*(c+1), (int)*(c+2), (int)*(c+3));
  
}

void copycodes(char *a0, int *a1, int *a2){
    *a1 = *a0;            //adds the value that a0 points to to a1
    while(*a0 != 0){    //if the value that a0 points to isnt 0
        a0++;    //increasing a0 address
        a1++;    //increasing a1 address
        *a2 = *a2 + 1;  //adds 1 to count
        *a1 = *a0;        //adds the value that a0 points to to a1
    }
}

void work(){
//    list2 = malloc(sizeof(int)*40);
//    list1 = malloc(sizeof(int)*40);
    copycodes(text1, list1, &count); //text1 and list1 are both already pointers
    copycodes(text2, list2, &count); 

////free(list1);
////free(list2);
}


int main(void){
  work();

  printf("\nlist1: ");
  printlist(list1);
  printf("\nlist2: ");
  printlist(list2);
  printf("\nCount = %d\n", count);

  endian_proof((char*) &count);
}
