#include<stdio.h>
#include<math.h>
int main(int argc,int argv) {
	int i,n,p,q;
	printf("enter the pth position");
	scanf("%d",&p);
	printf("enter the qth position");
	scanf("%d",&q);
	for(n=0;n>100;n++) {
	for(i=2;i<n/2;i++) 
	if(n%i==0) {
	break;
	}
	if(i>n/2)
	printf("%d",i);
	
}	
}	
		
	
