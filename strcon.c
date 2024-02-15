#include<stdio.h>
#include<string.h>
int main() {
char a[20]="cpp";
char b[20]="programming";
 int len=0,i;
for(i=0;a[i]!='\0';i++) {
	len++;
}
for(i=0;b[i]!='\0';i++) {
	a[len+i]=b[i];
}
a[len+i]='\0';
printf("%s",a);
}

