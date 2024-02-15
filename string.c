#include<stdio.h>
int main() {
	char a[]="helloworld";
	int i=0,count=0;
	for(i=0;a[i]!='\0';i++) {
		count++;
	}
	printf("%d",count);
}
