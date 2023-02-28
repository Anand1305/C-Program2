#include<stdio.h>

void Display(int Arr[],int iSize)
{
	static int iCnt = 0;
	
	while(iCnt < iSize)
	{
		printf("%d\n",Arr[iCnt]);
		iCnt++;
		Display(Arr,iSize);
	}
}

int main()
{
	int Arr[5] = {10,20,30,40,50};
	
	
	Display(Arr,5);
	

	
	return 0;
}