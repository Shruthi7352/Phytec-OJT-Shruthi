#include<stdio.h>
#include<string.h>
int main() {
char a[]="programming";
 int i=0,j=0;
 char temp=0;
while(a[j]!='\0') {
	j++;
}
j=j-1;
while(i<j) {
temp=a[i];
a[i]=a[j];
a[j]=temp;
j--;
i++;
}
printf("the reversed string is %s",a);
}


