#include<stdio.h>

int Addition(int Arr[],int iSize)
{
	static int iCnt = 0;
	static int iSum = 0;
	
	while(iCnt < iSize)
	{
		iSum = iSum + Arr[iCnt];
		iCnt++;
		Addition(Arr,iSize);
	}
	return iSum;
}

int main()
{
	int Arr[5] = {10,20,30,40,50};
	int Ret = 0;
	
	
	Ret = Addition(Arr,5);
	printf("%d",Ret);
	

	
	return 0;
}