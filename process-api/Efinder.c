#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int rc, fd[2];
	const int buf_size = 2048;
	char buf[buf_size];
	if(pipe(fd) < 0){
		printf("pipe failed\n");
		return 1;
	}
	if(argc != 2){
		printf("Must be of two arguments\n");
		return 1;
	}
	rc = fork();
	if(rc < 0){
		printf("fork failed\n");
		return 1;
	}else if(rc == 0){
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execlp("grep", "grep", "-i","-o", "e", argv[1], (char*)NULL);
		close(fd[1]);
		return 0;
	}else{
		wait(NULL);
		close(fd[1]);
		dup2(fd[0], 0);
		execlp("wc", "wc", "-l", (char*)NULL);
		return 0;
	}
}
