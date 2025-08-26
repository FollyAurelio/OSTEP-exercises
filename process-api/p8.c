#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char **argv)
{
	int fd[2] = {0, 1};
	if(pipe(fd) == -1){
		printf("An error occurend with the pipes\n");
		return 1;
	}
	int rc, wc;
	rc = fork();
	if(rc |= 0){
		wc = fork();
	}
	if (rc < 0 || wc < 0){
		printf("Failed to create process\n");
		return 1;
	}else if (rc == 0){
		//write(fd[1], "s", 1);
		//printf("%d\n",fd[0]);
		dup2(fd[1], 1);
		printf("%s", "ok");
		return 0;
	}else if (wc == 0){
		waitpid(rc, NULL, 0);
		dup2(fd[0], 0);
		char s[2];
		//printf("Hello am the child 2 (pid : %d)\n", (int)getpid());
		//read(fd[0], s, 1);
		//printf("%s\n", s);
		//scanf("%s", s);
		read(0, s, 2);
		printf("%s\n", s);

		return 0;
	}else{
		//printf("Goodbye am the parent (pid : %d)\n", (int)getpid());
		return 0;
	}
}
