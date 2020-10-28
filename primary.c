#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
#include <stdlib.h>

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
	int num = atoi(argv[1]);
	int check_num = num;
	while (check_num != 0 && (check_num % 10) <= 1 )
	{
 	  	check_num /= 10;
	}
	if ((check_num % 10) > 1 )
	{	
		printf("Not binary number!");
		return 0;
	}
	int dec_num = convert(num);
	if (isPrime(dec_num)){
	printf("This is prime number");
	}
	else{
		printf("This isn't prime number");
	}
	return 0;
}
