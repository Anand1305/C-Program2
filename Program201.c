#include<stdio.h>

int CountOnBits(unsigned int No)
{
	int iCnt = 0;
	int iDigit = 0;
	
	while(No != 0)
	{
		iDigit = No % 2;
		if(iDigit == 1)
		{
			iCnt++;
		}
		No = No / 2;
	}
	return iCnt;
}

int main()
{
	unsigned int Value = 0;
	int Ret = 0;
	
	printf("Enter number : \n");
	scanf("%d",&Value);
	
	Ret = CountOnBits(Value);
	
	printf("Number of bits which are ON : %d\n",Ret);
	
	return 0;
}