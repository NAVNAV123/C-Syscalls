#include<stdio.h>
#include<math.h>
#include<stdbool.h>

int convert(int number){
	int dec = 0, i = 0, remainder;
	while (number != 0){
		remainder = number % 10;
		number = number / 10;
		dec += remainder*pow(2,i);
		i++;
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
	int num = *argv[1];
	num = convert(num);
	if (isPrime(num)){
	printf("This is prime number");
	}
	else{
		printf("This is prime number");
	}
	return 0;
}
