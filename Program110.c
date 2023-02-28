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
	printf("The Elements of Linked List are\n")
	while(First != NULL)
	{
		printf("| %d | -> ",First -> digit);
		First = First -> next;
	}
	printf("NULL \n");
}

void Count(PNODE First)
{
	int iCnt = 0;
	while(First != NULL)
	{
		iCnt ++;
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
		(*First) = (*First) -> next;
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
	else if((*First) -> next == NULL)
	{
		free(*First);
		*First = NULL;
	}
	else
	{
		while(temp -> next -> next != NULL)
		{
			temp = temp -> next;
		}
		free(temp -> next);
		temp -> next = NULL;
	}
}

void InsertAtPosition(PPNODE First, int no, inr ipos)
{
	int iCnt = 0, NodeCnt = 0;
	PNODE temp = NULL;
	PNODE newn = NULL;
	
	NodeCnt = Count(*First);
	
	if((ipos < 1)||(ipos > NodeCnt+1))
	{
		return;
	}
	if(ipos == 1)
	{
		InsertFirst(First,no);
	}
	else if(ipos == NodeCnt+1)
	{
		InsertLast(First,no);
	}
	else
	{
		PNODE newn = (PNODE)malloc(sizeof(NODE))
		newn -> data = no;
		newn -> next = NULL;
		
		temp = *First;
		
		for(iCnt = 1; iCnt < ipos - 1; iCnt++)
		{
			temp = temp -> next;
		}
		newn -> next = temp -> next;
		temp -> next = newn;
	}
}

void DeleteAtPosition(PPNODE First, int no, inr ipos)
{
	int iCnt = 0, NodeCnt = 0;
	PNODE temp1 = NULL;
	PNODE temp2 = NULL;
	
	NodeCnt = Count(*First);
	
	if((ipos < 1)||(ipos > NodeCnt+1))
	{
		return;
	}
	if(ipos == 1)
	{
		InsertFirst(First,no);
	}
	else if(ipos == NodeCnt+1)
	{
		InsertLast(First,no);
	}
	else
	{
		temp1 = *First;
		for(iCnt = 1; iCnt < ipos -1 ; iCnt++)
		{
			temp1 = temp1 -> next;
		}
		temp2 = temp1 -> next;
		temp1 -> next = temp1 -> next -> next;
		free(temp2);
	}

int main()
{
	PNODE Head = NULL;
	
	return 0;
}