#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int iterativePower(int a, int n){

	if(n <= 0) return -1;
	if(n == 1) return a;
	
	int i,tmp = a;
	
	for (i = 0; i < n-1; i++){
	  	a *= tmp;
	}
	
	return a;
}


int recursivePower(int a, int n){

	if(n <= 0) return -1;
	if(n == 1) return a;
	
	return a*recursivePower(a, n-1);
}

int main(int argc, char *argv[]){

	int resultIterative,resultRecursive;
	
	resultIterative = iterativePower(2,3);
	resultRecursive = recursivePower(2,3);	
	
	printf("%d\n", resultIterative);
	printf("%d", resultRecursive);
	
	printf("\n");
	
	return 0;
}
