#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)

struct node
{
	int data;
	struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InserFirst(PPNODE First, int no )
{
	PNODE newn = (PNODE)malloc(sizeof(NODE));
	newn -> data = no;
	newn -> next = NULL;
	
	if(*First == NULL)
	{
		*First = newn;
	}
	else
	{
		newn -> next = *First;
		*First = newn;
	}
}

void InsertLast(PPNODE First, int no)
{
	PNODE newn = (PNODE)malloc(sizeof(NODE));
	PNODE temp = *First;
	newn -> data = no;
	newn -> next = NULL;
	
	if(*First == NULL)
	{
		*First = newn;
	}
	else
	{
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = newn;
	}
}

void Display(PNODE First)
{
	printf("The Elements of Linked list are\n");
	while(First != NULL)
	{
		printf("| %d | -> ", First -> data);
		First = First -> next;
	}
	printf("NULL \n");
}

int Count(PNODE First)
{
	int iCnt = 0;
	while(First != NULL)
	{
		iCnt++;
		First = First -> next;
	}
	return iCnt;
}
	
void DeleteFirst(PPNODE First)
{
	PNODE temp = *First;
	
	if(*First == NULL)
	{
		return;
	}
	else if((*First) -> next == NULL)
	{
		free(*First);
		*First = NULL;
	}
	else
	{
		(*First)= (*First) -> next;
		free(temp);
	}
}

void DeleteLast(PPNODE First)
{
	PNODE temp = *First;
	
	if(*First == NULL)
	{
		return;
	}
	else if((*First) -> next ==  NULL)
	{
		free(*First);
		*First = NULL;
	}
	else
	{
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		free(temp -> next);
		temp -> next = NULL;
	}
}

void InserAtPosition(PPNODE First , int no, int ipos)
{
	PNODE newn = NULL;
	PNODE temp = NULL;
	int iCnt = 0,NodeCount = 0;
	
	NodeCount = Count(*First);
	
	if((ipos < 1) || (ipos >(NodeCount + 1) ))
	{
		return;
	}
	if(ipos == 1)
	{
		InserFirst(First,no);
	}
	else if(ipos == NodeCount+1)
	{
		InsertLast(First,no);
	}
	else
	{
		newn = (PNODE)malloc(sizeof(NODE));
		
		newn -> data = no;
		newn -> next = NULL;
		temp = *First;
		
		for(iCnt = 1; iCnt < ipos -1 ; iCnt++)
		{
			temp = temp -> next;
		}
		newn -> next  = temp -> next;
		temp -> next = newn;
	}
}	

void DeleteAtPostion(PPNODE First, int ipos)
{
	PNODE temp = NULL;
	PNODE temp2 = NULL;
	int iCnt = 0;
	int NodeCount = 0;
	
	NodeCount = Count(*First);
	
	if((ipos < 1) || (ipos > NodeCount))
	{
		return;
	}
	if(ipos == 1)
	{
		DeleteFirst(First);
	}
	else if(ipos == NodeCount)
	{
		DeleteLast(First);
	}
	else
	{
		temp = *First;
		
		for(iCnt = 1; iCnt < ipos - 1;iCnt++)
		{
			temp = temp -> next;
		}
		temp2 = temp ->next;
		temp -> next = temp -> next -> next;
		free(temp2);
	}

}

int main()
{
	PNODE Head = NULL;
	int iRet = 0;
	
	
	InserFirst(&Head,11);
	InserFirst(&Head,20);
	InserFirst(&Head,56);
	
	Display(Head);
	
	iRet = Count(Head);
	
	printf("The Number of elements in linked list are %d \n",iRet);
	
	InsertLast(&Head,90);
	InsertLast(&Head,100);
	
	Display(Head);
	
	iRet = Count(Head);
	
	printf("The Number of elements in linked list are %d \n",iRet);
	
	DeleteFirst(&Head);
	
	Display(Head);
	
	iRet = Count(Head);
	
	printf("The Number of elements in linked list are %d ",iRet);
	
	InserAtPosition(&Head,134,3);
	
	Display(Head);
	
	iRet = Count(Head);
	
	printf("The Number of elements in linked list are %d \n",iRet);
	
	DeleteAtPostion(&Head,3);
	
	Display(Head);
	
	iRet = Count(Head);
	
	printf("The Number of elements in linked list are %d \n",iRet);
	
	
	
	return 0;
}