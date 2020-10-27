#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

int convert(char *number){
	int dec = 0, i = 0, base = 1, len = strlen(number);
	for (i = len -1; i >= 0; i --){
		if (number[i] == '1')
			dec += base;
		base = base * 2;
	}
	return dec;
}

bool isPrime(int number){
	for (int i = 2; i <= sqrt(number); i++)
	{
		if (number % i == 0)
			return false;
	}
	return true;
}

int main(int argc, char *argv[]){
	char *num = argv[1];
	dec_num = convert(num);
	if (isPrime(dec_num)){
	printf("This is prime number");
	}
	else{
		printf("This isn't prime number");
	}
	return 0;
}
