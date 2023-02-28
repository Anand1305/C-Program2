//	*	*	*	*

#include<stdio.h>

void DisplayR(int No)
{
	static int iCnt = 1;	//static
	
	if(iCnt <= No)
	{
		printf("*\t");
		iCnt++;
		DisplayR(No);	//Recursive Call
	}
}

int main()
{
	int Value = 0;
	printf("Enter the number\n");
	scanf("%d",&Value);
	printf("Inside Main \n");
	
	DisplayR(Value);
	
	printf("\nEnd of Main\n");
	
	return 0;
}