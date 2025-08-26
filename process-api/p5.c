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
		printf("Hello am the child (pid : %d)\n", (int)getpid());
		int w = wait(NULL);
		printf("%d\n", w);
		execl("/bin/ls", "/bin/ls", "-a",  (char*)NULL);
	}else{
		int w = wait(NULL);
		printf("Goodbye am the parent (pid : %d), wait : %d\n", (int)getpid(), w);
	}
	return 0;
}

//wait() returns the process id of the child, just like fork()
//wait() returns -1 when done in the child, and the process continues executing
