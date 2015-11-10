#include <pthread.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

pthread_t tid[100];

int range;
int thread_num;

bool isPrime(int num){

	for(int i = 2; i < num; i++)
		if(num % i == 0)
			return false;

	return true;
}

void *funct(void *param){

	int tid = (int) param;

	int min = (tid*(range/thread_num)+1);
	int max = (tid+1)*(range/thread_num);

	for(int i = min; i <= max; i++){

		if(isPrime(i)==true)
			printf("THREAD#%d : %d\n", tid, i);
	}
}

int main (int argc, char *argv[]){


	if(argc != 3){

		printf("INVALID NUMBER OF PARAMS!\n");
		printf("%s <RANGE> <THREAD_NUM>\n", argv[0]);
		exit(-1);
	}

	range = atoi(argv[1]);

	thread_num = atoi(argv[2]);

	if(thread_num > range){

		printf("THREAD_NUM MUST BE SMALLER THAN RANGE!\n");
		exit(-1);
	}


	for(int i = 0; i < thread_num; i++)
	 run(	pthread_create(&tid[i] ,NULL, funct, (void*)i);

	for(int i = 0; i < thread_num; i++)
		pthread_join(tid[i],NULL);
}

