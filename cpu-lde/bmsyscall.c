#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>

int main()
{
	struct timeval start;
	struct timeval end;
	gettimeofday(&start, NULL);
	for(int i = 0; i < 1000; i++)printf("fsadfasdf");
	gettimeofday(&end, NULL);
	printf("ms : %f\n", (float=((end.tv_sec * 1000000 + sv.end) - (start.tv_sec * 1000000 + start.tv_usec)) / 1000);
}
