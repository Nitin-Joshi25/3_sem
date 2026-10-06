#include<stdio.h>
int main(){
	int n1 ,n2;
	char c;
	printf("The value of n1 : \n ");
	scanf("%d",&n1);
	printf("The value of n2 : \n ");
	scanf("%d",&n2);
	
	printf("Enter the operator(+,-,/,*,%) : \n");
	scanf("%c",&c);
	switch(c){
	case '+': printf("The  addition of n1 and n2 %d",(n1+n2));
	break;
	case '-': printf("The  subtraction of n1 and n2 %d",(n1-n2));
	break;
	
	case '/': printf("The  division of n1 and n2 %d",(n1/n2));   
	break;
	
	case '*':	printf("The multiplication of n1 and n2 %d",(n1*n2));
	break;
	
	case '%' : printf("The  modulus of n1 and n2 %d",(n1%n2));
	break;
	default: printf("The operation is invalid");
	}
	return 0;
}