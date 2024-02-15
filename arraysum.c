#include<stdio.h>
void  sum_array(int c[],int d[]) {
int sum[5];
for(int i=0;i<5;i++) {
sum[i]=c[i]+d[i];	
printf("%d ",sum[i]);
}
}
int main() {
int a[]={2,4,6,8,10};
int b[]={1,3,5,7,9};
sum_array(a,b);
}



