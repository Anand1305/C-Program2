// Accept String from user and calculate the frequency of 'a' & 'A'

// Accept Full Name Display on Screen
#include<stdio.h>

int CountFreq(char *str)
{
	int iCnt = 0;
	
	while(*str != '\0')
	{
		if((*str == 'a') || (*str == 'A'))
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
	
	iRet = CountFreq(Arr);	//strlenx(100)
	printf("Number of 'a' are %d\n",iRet);
	
	return 0;
}