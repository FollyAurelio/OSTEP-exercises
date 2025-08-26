#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char **argv)
{
	int rc = fork();
	if (rc < 0){
		printf("Failed to create process\n");
		exit(1);
	}else if(rc == 0){
		close(1);
		printf("Hello am the child (pid : %d)\n", (int)getpid());
	}else{
		wait(NULL);
		printf("Goodbye am the parent (pid : %d)\n", (int)getpid());
	}
	return 0;
}

//The child program no longer prints as the standard output has been closed
