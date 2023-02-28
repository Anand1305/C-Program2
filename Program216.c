//	4
//	4 *	3 *	2 *	1 = 24

#include<stdio.h>
int FactorialR(int No)
{
	static int mul = 1;
	static int iCnt = 1;
	
	if(iCnt <= No)
	{
		mul = mul * iCnt;
		iCnt++;
		FactorialR(No);
	}
	return mul;
}

int main()
{
	int Value = 0,Ret = 0;
	printf("Enter the number\n");
	scanf("%d",&Value);
	
	Ret = FactorialR(Value);
	printf("Addition is : %d\n",Ret);
	
	return 0;
}