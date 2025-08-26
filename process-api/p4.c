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
		printf("Goodbye am the parent (pid : %d)\n", (int)getpid());
	}
	return 0;
}

//we have different versions of exec to accomodate argument passing conventions of the lanuage
