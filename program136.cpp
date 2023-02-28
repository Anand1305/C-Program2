#include<iostream>
using namespace std;

#pragma pack(1)

struct node
{
	int data;
	struct node * next;
	struct node * prev;
};

typedef struct node NODE;
typedef struct node * PNODE;

class DoubleyCL
{
	public:
		PNODE First;
		PNODE Last;
		
		DoubleyCL();
		
		void InsretFirst(int no);
		void InsretLast(int no);
		void InsertAtPos(int no,int ipos);
		
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int ipos);
		
		void Display();
		int Count();
};

DoubleyCL :: DoubleyCL()
{
	First = NULL;
	Last = NULL;
}

void DoubleyCL :: InsretFirst(int no)
{
	PNODE newn = new NODE;
	
	newn -> data = no;
	newn -> next = NULL;
	newn -> prev = NULL;
	
	if(First == NULL && Last == NULL)
	{
		First = Last = newn;
		First -> prev = Last;
		Last -> next = First;
		
		
	}
	
	else
	{
		newn -> next = First;
		First -> prev = newn;
		First = newn;
		First -> prev = Last;
		Last -> next = First;
		
	}
}

void DoubleyCL :: InsretLast(int no)
{
	PNODE newn = new NODE;
	
	newn -> data = no;
	newn -> next = NULL;
	newn -> prev = NULL;
	
	if(First == NULL && Last == NULL)
	{
		First = Last = newn;
		First -> prev = Last;
		Last -> next = First;
		
		
	}
	
	else
	{
		Last -> next = newn;
		newn -> prev = Last;
		Last = newn;
		First -> prev = Last;
		Last -> next = First;
	}
}

void DoubleyCL :: DeleteFirst()
{
	if(First == NULL && Last == NULL)
	{
		return;
	}
	else if(First == Last)
	{
		delete First;
		First = NULL;
		Last = NULL;
	}
	else
	{
		
		First = First -> next;
		delete First -> prev;
		First -> prev = Last;
		Last -> next = First;
		
	}
}

void DoubleyCL :: DeleteLast()
{
	PNODE temp = First;
	if(First == NULL && Last == NULL)
	{
		return;
	}
	else if(First == Last)
	{
		delete First;
		First = NULL;
		Last = NULL;
	}
	else
	{
		while(temp -> next != Last)
		{
			temp = temp -> next;
		}
		delete temp -> next;
		Last = temp;
		First -> prev = Last;
		Last -> next = First;
	}
}

void DoubleyCL :: Display()
{
	PNODE temp = First;
    cout<<"Elements of Linked list are :"<< "\n";

    do
    {
        cout<<"|"<<temp->data<<"|"<<" -> ";
        temp = temp -> next;
    }while(temp != Last->next);
	cout<<"\n";
}

int main()
{
	DoubleyCL obj;
	
	obj.InsretFirst(51);
	obj.InsretFirst(21);
	obj.InsretFirst(11);
	
	obj.InsretLast(100);
	obj.InsretLast(200);
	obj.InsretLast(300);
	
	
	obj.Display();
	
	obj.DeleteFirst();
	obj.DeleteLast();
	obj.Display();
	
	return 0;
}