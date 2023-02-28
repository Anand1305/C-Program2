#include<stdio.h>

typedef unsigned int UINT;

//	0000	0000	0000	0000	0000	0000	0000	0000

//	1111	1111	1111	1111	1111	1111	1111	0111

//	0XFFFFFFF7

UINT OffBit(UINT NO)
{
	UINT iMask = 0XFFFFFFF7;
	UINT iAns = 0;
	
	iAns = NO& iMask;
	
	return iAns;
}

int main()
{
	UINT Value = 0;
	UINT iRet = 0;
	
	printf("Enter Number : \n");
	scanf("%d",iRet);
	
	printf("Enter number : \n");
	scanf("%d",&Value);
	
	iRet = OffBit(Value);
	
	printf("%d\n",iRet);
	
	return 0;
	
}