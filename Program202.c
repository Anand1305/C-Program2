#include<stdio.h>

typedef unsigned int UINT;

int CountOnBits(UINT  No)
{
	int iCnt = 0;
	int iDigit = 0;
	
	while(No != 0)
	{
		iDigit = No % 2;
		iCnt = iCnt + iDigit;
		No = No / 2;
	}
	return iCnt;
}

int main()
{
	UINT  Value = 0;
	int Ret = 0;
	
	printf("Enter number : \n");
	scanf("%d",&Value);
	
	Ret = CountOnBits(Value);
	
	printf("Number of bits which are ON : %d\n",Ret);
	
	return 0;
}