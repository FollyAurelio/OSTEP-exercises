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
		execl("/bin/ls", "/bin/ls", "-a",  (char*)NULL);
	}else{
		int w = waitpid(rc, NULL, 0);
		printf("Goodbye am the parent (pid : %d), wait : %d\n", (int)getpid(), w);
	}
	return 0;
}
