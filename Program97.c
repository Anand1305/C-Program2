// Accept  
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
	
	
	printf("Enetr String\n");
	scanf("%[^'\n']s",&Arr);
	
	iRet = FrequencyOfLetter(Arr,'a');	//strlenx(100)
	printf("Number of Small Charter are %d\n",iRet);
	
	return 0;
}