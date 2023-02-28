// Accept string and char and check whether the charcter prsent in the string or not
#include<stdio.h>
#include<stdbool.h>

int Chek(char *str,char ch)
{
	bool bFlag = false;
	while(*str != '\0')
	{
		if(*str == ch)
		{
			bFlag = true;
			break;
		}
		str++;
	}
	return bFlag;
}
int main()
{
	char Arr[20];
	bool bRet = false;
	char cValue = '\0';
	
	
	printf("Enetr String\n");
	scanf("%[^'\n']s",&Arr);
	
	printf("Please Enter the chartecter \n");
	scanf(" %c",&cValue);
	
	bRet = Chek(Arr,cValue);	//strlenx(100)
	
	if(bRet == true)
	{
		printf("Charcter is prsent");
	}
	else
	{
		printf("NO");
	}
	
	
	return 0;
}