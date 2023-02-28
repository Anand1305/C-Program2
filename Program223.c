#include<stdio.h>

void DisplayR(char *str)
{
	static int iCnt = 0;
	
	if(*str != '\0')
	{
		printf("%s\n",str);
		str++;
		DisplayR(str);
	}
}

int main()
{
	char Arr[20];
	int iRet = 0;
	
	printf("Enter String : \n");
	scanf("%[^'\n']s",Arr);
	
	DisplayR(Arr);
	
	printf("String length is : %d\n",iRet);
	
	return 0;
}