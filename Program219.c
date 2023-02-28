#include<stdio.h>
#include<stdbool.h>

bool PerfectR(int No)
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
		PerfectR(No);
	}
	if(iSum == No)
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
	int Value = 0;
	bool bRet = false;
	printf("Enter the number\n");
	scanf("%d",&Value);
	
	bRet = PerfectR(Value);
	if(bRet == true)
	{
		printf("True");
	}
	else
	{
		printf("False");
	}
	
	
	return 0;
}