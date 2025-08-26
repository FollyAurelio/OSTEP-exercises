#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	int x = open("dummy", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);

	int rc = fork();
	if (rc < 0){
		printf("Failed to create process\n");
		exit(1);
	}else if(rc == 0){
		printf("I am the child (pid : %d), x : %d\n", (int)getpid(), x);
		write(x, "the\n", 4);
		close(x);
	}else{
		printf("I am the parent (pid : %d), x : %d\n", (int)getpid(), x);
		wait(NULL);
		write(x, "cat\n", 4);
	}
	return 0;
}

//The two processes create copies of their stack frames, so the file they refer to are the same 
//They can write to the file concurrently
//If the child executes first and closes the file, the parent can still write to it, as it has a copy of the file descriptor.
