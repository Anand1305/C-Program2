#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE First,int no)
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

void InsertLast(PPNODE First,int no)
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
	PNODE temp = *First;
	
	printf("Elements of The Linked List are : \n");
	
	while(First != NULL)
	{
		printf("| %d | -> ",First -> data);
		First = First -> next;
	}
	printf("NULL \n");
}

void DeleteFirst(PPNODE First)
{
	PNODE temp = *First;
	if(*First == NULL)
	{
		printf("There is No node to delete\n");
		return;
	}
	else if((*First) -> next == NULL)
	{
		free(*First)
		*First = NULL;
	}
	else
	{
		(*First) = *First -> next;
		free(temp);
	}
}

void DeleteLast(PPNODE First)
{
	PNODE temp = *First;
	
	if(*First == NULL)
	{
		printf("There is No node to delete\n");
		return;
	}
	else if((*First) -> next == NULL)
	{
		free(*First)
		*First = NULL;
	}
	else
	{
		while(temp -> next -> next != NULL )
		{
			temp = temp -> next;
		}
		free(temp -> next);
		temp -> next = NULL;
	}
}

int Count(PNODE First)
{
	int iCnt = 0;
	printf("Elements of The Linked List are : \n");
	
	while(First != NULL)
	{
		iCnt++;
		First = First -> next;
	}
	return iCnt;
}


int main()
{
	PNODE Head = NULL;
	int iRet = 0;
	
	InsertFirst(&Head,10);
	InsertFirst(&Head,20);
	InsertFirst(&Head,30);
	
	Display(Head);
	
	iRet = Count(Head);
	
	printf("The Element Count in Linked List are : %d\n",iRet);
	
	Display(Head);
	
	InsertLast(&Head,100);
	InsertLast(&Head,200);

	
	
	iRet = Count(Head);
	
	printf("The Element Count in Linked List are : %d\n",iRet);
	

	return 0;
}