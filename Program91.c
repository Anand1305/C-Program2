// Accept Full Name Display on Screen
#include<stdio.h>

int strlenX(char *str)
{
	int iCnt = 0;
	
	while(*str != '\0')
	{
		iCnt++;
		str++;
	}
	return iCnt;
}
int main()
{
	char Arr[20];
	int iRet = 0;
	
	printf("Enetr String\n");
	scanf("%[^'\n']s",&Arr);
	
	iRet = strlenX(Arr);	//strlenx(100)
	printf("Number of Charter are %d\n",iRet);
	
	return 0;
}