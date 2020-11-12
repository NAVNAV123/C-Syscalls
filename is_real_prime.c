#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<unistd.h>
#include<stdlib.h>
#include <string.h>

bool isPrime(int number){
        for (int i = 2; i <= sqrt(number); i++)
        {
                if (number % i == 0)
                        return false;
        }
        return true;
}


int main(int argc, char *argv[]){
        int num;
        int i = 0;
        for(i = 1; i < argc; i++){
                num = atoi(argv[i]);
                if(isPrime(num)){
                        write(1, argv[i], strlen(argv[i]));
                }
        }
}

