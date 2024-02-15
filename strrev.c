#include<stdio.h>
#include<string.h>
int main() {
char a[20]="programming";
char b[20];
 int len=0,i;
for(i=0;a[i]!='\0';i++) {
	len++;
}
for(i=0;i<len;i++) {
	b[i]=a[len-i-1];
}
b[i]='\0';
printf("the original string is %s\n",a);
printf("the reversed string is %s",b);
}

