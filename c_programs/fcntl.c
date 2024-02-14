#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int fd=open("/etc/passwd",O_RDONLY);
	printf("The first file descriptor is %d\n",fd);
	int rv = fcntl(fd, F_DUPFD, 54);
	printf("Duplicate file descriptor is %d\n",rv);
	return 0;
}
