#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 25

void sort( int numbers[], int count )
{
    int i, j;

    int temp;
    do{
        j = 0;
        for (i = 0;i<=count;i++){
			if (numbers[i] > numbers[i+1]){
				j = 1;
				temp = numbers[i];
				numbers[i] = numbers[i+1];
				numbers[i+1] = temp;
			}
		}
    } while (j == 1);
}

int search(int n, int t[],int debut, int fin){
	int milieu;
	if(debut > fin){
		return 0;
	}
	else{
		milieu = (debut +fin)/2;
		if(t[milieu] == n){
			return 1;
		}
		else{
			if(t[milieu]<n)
				return search(n,t,milieu+1,fin);
			else
				return search(n,t,debut,milieu-1);
		}
	}
}

int i_search(int n, int t[],int debut, int fin){
	int milieu;

	while(1){
		if(debut > fin){
			return 0;
		}
		else{
			milieu = (debut +fin)/2;
			if(t[milieu] == n){
				return 1;
			}
			else{
				if(t[milieu]<n){
					debut = milieu +1;
				}
				else{
					fin = milieu -1;
				}
			}
		}
	}
}

int main(int argc, char **argv) {
	int t[N];
	int i;
	srand(time(NULL));

	for(i=0; i<N; i++){
		t[i] = rand()%50;
		printf("%d ",t[i]);
	}
	printf("\n");

	sort(t,N);
	for(i=0; i<N; i++){
		printf("%d ",t[i]);
	}
	printf("\n");

	printf("%d\n",i_search(11,t,0,N-1));

	return 0;
}
