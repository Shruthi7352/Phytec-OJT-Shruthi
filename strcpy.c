#include<stdio.h>
#include<string.h>
int main() {
	char a[20]="c programming";
	char b[20];
	int i=0;
	for(i=0;a[i]!='\0';i++) {
		b[i]=a[i];
	}
	b[i]='\0';
	printf("%s ",b);
}
