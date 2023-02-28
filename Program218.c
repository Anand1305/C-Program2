#include<stdio.h>
int FactorsR(int No)
{
	static int iCnt = 1;
	static int iSum = 0;
	
	if(iCnt <= (No/2))
	{
		if((No % iCnt) == 0)
		{
			iSum = iSum + iCnt;
		}
		iCnt++;
		FactorsR(No);
	}
	return iSum;
}

int main()
{
	int Value = 0,Ret = 0;
	printf("Enter the number\n");
	scanf("%d",&Value);
	
	Ret = FactorsR(Value);
	printf("%d",Ret);
	
	return 0;
}