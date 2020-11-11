#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "defs.h"

int main(int argc, char *argv[]){
    int pipe_fd[2], c, status;
    pid_t p;
    FILE *f;

    if (pipe(pipe_fd) == -1){
            fprintf(stderr, "Pipe Failed");
			CLEAN(EXIT_FAILURE);
    }

    p = fork();
    switch(p) {
	case -1:
		fprintf(stderr, "Fork Failed");
		CLEAN(EXIT_FAILURE);
		break;
	case 0:
		if (argc == 1){
			printf("You don't type any number, Please type numberes through argv");
			CLEAN(EXIT_FAILURE);
		}
		dup2(pipe_fd[1], 1);
		close(pipe_fd[0]);
		execve("./is_real_prime", argv, NULL);
		break;
	default:
		close(pipe_fd[1]);
		f = fdopen(pipe_fd[0], "r");
		c = getc(f);
		while (c != EOF){
			putchar(c);
			c = getc(f);
			if (c == EOF)
				break;
			printf(", ");
		}
		CLEAN(EXIT_SUCCESS);
		exit(0);
	}
cleanup:
	if(fcntl(pipe_fd[0], F_GETFD) != -1 || errno != EBADF)
		close(pipe_fd[0]);
	if (fcntl(pipe_fd[1], F_GETFD) != -1 || errno != EBADF)
		close(pipe_fd[1]);
	return status;
}