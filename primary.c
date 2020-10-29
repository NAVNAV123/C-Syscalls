#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
#include <stdlib.h>

bool isPrime(int number){
	for (int i = 2; i <= sqrt(number); i++)
	{
		if (number % i == 0)
			return false;
	}
	return true;
}

int main(int argc, char *argv[]){
	if(argc == 1){
		printf("You don't type any number, Please type numberes throw argv");
		return 0;
	}
	int num;
	int i = 0;
	for(i = 1; i < argc; i++){
		num = atoi(argv[i]);
		if(isPrime(num)){
			printf("%d ", num);
		}
	}
	return 0;
}
