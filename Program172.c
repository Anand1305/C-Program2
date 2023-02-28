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


void InsertLast(PPNODE First, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));      
    PNODE temp = *First;
    newn->data = no;
    newn->next = NULL;

    if(*First == NULL)  
    {
        *First = newn;
    }
    else                
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
}

void InsertFirst(PPNODE First, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));      

    newn->data = no;
    newn->next = NULL;

    if(*First == NULL) 
    {
        *First = newn;
    }
    else                
    {
        newn->next = *First;
        *First = newn;
    }
}

void Display(PNODE First)
{
    printf("Elements from the Linked List are : \n");

    while(First != NULL)
    {
        printf("| %d |-> ",First->data);
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

    if(*First == NULL)  // A
    {
        return;
    }
    else if((*First) -> next == NULL) //B
    {
        free(*First);
        *First = NULL;
    }
    else // C
    {
        (*First) = (*First) -> next;
        free(temp);
    }
}

void DeleteLast(PPNODE First)
{
    PNODE temp = *First;

    if(*First == NULL)  // Empty LL
    {
        return;
    }
    else if((*First) -> next == NULL) // 1 node in LL
    {
        free(*First);
        *First = NULL;
    }
    else // More than 1 node in LL
    {
        while(temp ->next -> next != NULL)
        {
            temp = temp -> next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void InsertAtPos(PPNODE First, int no, int ipos)
{
    int NodeCnt = 0, iCnt = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    NodeCnt = Count(*First);

    if((ipos < 1) || (ipos > (NodeCnt + 1)))
    {
        printf("Invalid position\n");
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
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;

        temp = *First;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next = newn;
    }
}

void DeleteAtPos(PPNODE First, int ipos)
{
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;
    int iCnt = 0, NodeCnt = 0;
    NodeCnt = Count(*First);

    if((ipos < 1) || (ipos > NodeCnt))
    {
        printf("Invalid position\n");
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst(First);
    }
    else if(ipos == NodeCnt)
    {
        DeleteLast(First);
    }
    else
    {
        temp1 = *First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next; 
        free(temp2);
    }
}

int main()
{
    PNODE Head = NULL;
	int iChoice = 0, iPos = 0, iRet = 0, iNo = 0;
	
	printf("Welcome to the data structure application written by Anand Atul Pande\n");
	
	while(1)
	{
		printf("-----------------------\n");
		
		printf("Please Select Desieerd option : \n");
		printf("1 : Insert new node at first position\n");
		printf("2 : Insert new node at second position\n");
		printf("3 : Insert new node at given postion position\n");
		printf("4 : delete  node at first position\n");
		printf("5 : delete  node at last position\n");
		printf("6 : delete  node at given postion position\n");
		printf("7 : display  linked list\n");
		printf("8 : count  nodes of linked list\n");
		
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1:
				printf("Enter The data that you want to insert : \n");
				scanf("%d",&iNo);
				
				InsertFirst(&Head,iNo);
				break;
			
			case 2:
				printf("Enter The data that you want to insert : \n");
				scanf("%d",&iNo);
				
				InsertLast(&Head,iNo);
				
				break;
				
			case 3:
				printf("Enter The data that you want to insert : \n");
				scanf("%d",&iNo);
				
				printf("Enter The postion  : \n");
				scanf("%d",&iPos);
				
				
				
				InsertAtPos(&Head,iNo,iPos);
				break;
				
			case 4:
				DeleteFirst(&Head);
				
				break;
				
			case 5:
				DeleteLast(&Head);
				break;
				
			case 6:
				printf("Enter The postion  : \n");
				scanf("%d",&iPos);
				
				DeleteAtPos(&Head,iPos);
				break;
				
			case 7:
				Display(Head);
				break;
				
			case 8:
				iRet = Count(Head);
				printf("Number of elements are : %d\n",iRet);
				break;
				
			case 9:
				printf("Thank you for using application\n");
				return 0;
				
			default:
				printf("Invalid Option\n");
				break;
		}
		
		printf("-----------------------");
	}
	

    return 0;
}
