#include<stdio.h>
int main() {
int a[]={4,5,7,9,2};
int l=0,sl=0,i;
for(i=0;i<5;i++) {
	if(a[i]>l) {
		sl=l;
		l=a[i];
	}
		else if(a[i]>sl) { 
		sl=a[i];
}
}
              printf("%d",sl);
		}
