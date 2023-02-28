// Accept Full Name Display on Captial digits count
#include<stdio.h>

int CountCapital(char *str)
{
	int iCnt = 0;
	
	while(*str != '\0')
	{
		if((*str >= 'A') && (*str <= 'Z'))
		{
			iCnt++;
		}
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
	
	iRet = CountCapital(Arr);	//strlenx(100)
	printf("Number of Captial Charter are %d\n",iRet);
	
	return 0;
}