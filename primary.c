#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>


bool isPrime(int number){
	for (int i = 2; i <= sqrt(number); i++)
	{
		if (number % i == 0)
			return false;
	}
	return true;
}

int main(int argc, char *argv[]){
	        int fd[2];
        pid_t p;

        if (pipe(fd) == -1){
                fprintf(stderr, "Pipe failed");
                return 1;
        }

        p = fork();

        if (p < 0){
                fprintf(stderr, "fork failed");
                return 1;
        }

        if (p == 0){
                close(fd[0]);

                if(argc == 1){
                    printf("You don't type any number, Please type numberes throw argv");
                    return 0;
                }
                int num;
                int i = 0;
                for(i = 1; i < argc; i++){
                       write(fd[1], argv[i], strlen(argv[i]));
                }
                close(fd[1]);
        }

        else{
                int i = 0, num;
                char number[100];

                close(fd[1]);
                read(fd[0], number, 100);
                
		num = atoi(number);
                if(isPrime(num)){
			printf("%d", num);
		}
               
	       	close(fd[0]);
                exit(0);
        }
}
