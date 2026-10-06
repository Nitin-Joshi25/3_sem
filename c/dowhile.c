#include<stdio.h>
int main(){
	int a,i =1 ;
	printf(" enter the value upto the range ");
	scanf("%d",&a);
    do {
    	printf("%d",i);
    	i++ ;
	} while(i<=a);
	
	return 0;
}