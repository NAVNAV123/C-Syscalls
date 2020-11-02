#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char *argv[]){
        int pipe_fd[2];
        pid_t p;

        if (pipe(pipe_fd) == -1){
                fprintf(stderr, "Pipe Failed");
                return 1;
        }

        p = fork();
        if (p < 0){
                        fprintf(stderr, "Fork Failed");
                        return 1;
        }
        else if(p == 0){
                close(pipe_fd[0]);
                if (argc == 1){
                        printf("You don't type any number, Please type numberes through argv");
                        close(pipe_fd[1]);
                        return 0;
                }
                dup2(pipe_fd[1], 1);
                close(pipe_fd[1]);
		execve("./is_real_prime", argv, NULL);
        }
        else{
                close(pipe_fd[1]);
                FILE *f = fdopen(pipe_fd[0], "r");
		int c = getc(f);
		while (c != EOF){
			putchar(c);
			c = getc(f);
			if (c == EOF)
				break;
			printf(", ");
		}
		close(pipe_fd[0]);
		exit(0);
        }
}
