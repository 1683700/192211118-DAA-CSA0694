#include<stdio.h>

int main()
{
	int n,fact=1;
	printf("Enter a number: \n");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		fact*=i;
	}
	printf("Factorial of %d is: %d",n,fact);
}
