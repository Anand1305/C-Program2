// Accept string and char and count frequency of char 
#include<stdio.h>

int FrequencyOfLetter(char *str,char ch)
{
	int iCnt = 0;
	
	while(*str != '\0')
	{
		if(*str == ch)
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
	char cValue = '\0';
	
	
	printf("Enetr String\n");
	scanf("%[^'\n']s",&Arr);
	
	printf("Please Enter the chartecter \n");
	scanf(" %c",&cValue);
	
	iRet = FrequencyOfLetter(Arr,cValue);	//strlenx(100)
	printf("the frequency of charchter %d\n",iRet);
	
	return 0;
}