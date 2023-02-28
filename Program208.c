#include<stdio.h>
#include<stdbool.h>

typedef unsigned int UINT;

bool CheckBit(UINT No,UINT Pos)
{
	UINT iMask = 0X00000001;
	UINT Result = 0;
	
	if((Pos < 1) || (Pos > 32))
	{
		printf("Invalid postion, it should between 1 to 32\n");
		return false;
	}
	
	iMask = iMask << (Pos - 1); //Dynamic Mask Formation
	
	Result = No & iMask;
	
	if(Result == iMask)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	UINT Value =0;
	UINT Postion = 0;
	bool bRet = false;
	
	printf("Enter number : \n");
	scanf("%d",&Value);
	
	printf("Enter the postion of bit\n");
	scanf("%d",&Postion);
	
	bRet = CheckBit(Value,Postion);
	
	if(bRet == true)
	{
		printf("Bit at the postion %d is ON\n",Postion);
	}
	else
	{
		printf("Bit at the postion %d is OFF\n",Postion);
	}
	
	return 0;
}