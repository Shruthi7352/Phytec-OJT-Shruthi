#include<stdio.h>
int main() {
	int a[]={1,2,3};
	int b[]={4,5,6};
	int c[6];
	int i,j;
	for(i=0;i<6;i++) {
		c[i]=a[i];
	}
	for(j=0;j<3;j++) {
		c[i+3]=b[j];
	}

	for(i=0;i<6;i++) {
		printf("%d",c[i]);
	}	
}
	
