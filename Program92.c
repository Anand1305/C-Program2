// Accept Full Name Display on Screen
#include<stdio.h>

int strlenX(char *str)
{
	int iCnt = 0, i = 0;
	
	while(str[i] != '\0')
	{
		iCnt++;
		i++;
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