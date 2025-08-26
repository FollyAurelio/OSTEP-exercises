#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int x = 100;

	int rc = fork();
	if (rc < 0){
		printf("Failed to create process\n");
		exit(1);
	}else if(rc == 0){
		x = 65;
		printf("I am the child (pid : %d), x : %d\n", (int)getpid(), x);
	}else{
		x = 85;
		printf("I am the parent (pid : %d), x : %d\n", (int)getpid(), x);
	}
	return 0;
}

//when you set a variable before calling fork, it will be equal to whatever that variable is set to in the child process,
//Each process has it own stack, so you can modify other variables without changing the other process
