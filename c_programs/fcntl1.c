#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int fd = open("abc.txt",O_RDWR);
	write(fd,"Hola Amigo",20);
	close(fd);
	int flags=fcntl(fd,F_GETFL,0);  //get settings
 	flags=flags | O_APPEND;		//Mmodify settings
 	fd = open("abc.txt",O_RDWR);
	write(fd,"Hola Pavithra",20);
	close(fd);
	fcntl(fd,F_GETFL,flags);		//set them back
        return 0;
}
