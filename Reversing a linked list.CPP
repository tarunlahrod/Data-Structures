
//------------------REVERSING A LINKED LIST-----------------------//

/* Reversing a linked list does not mean to print the node -> data in reversed order, it actually means to reversing the links

	For reversing a linked list, we have two approaches
   	1. Iterative
      2. Recursive

*/




#include <iostream.h>
#include <conio.h>

struct node
{
	int data;
	node *next;
} *head;

//-------------- Recursive --------------//

void reverseRecursive(node *p)
{
	if(head == NULL)
   	return;


	if(p -> next == NULL)    //exit condition or base condition
   {
   	head = p;
      return;
   }

   reverseRecursive(p -> next);

   //we are writing the logic for reversal after the recursive statement to start reversing from the last node

   node *q;

   q = p -> next;
   q -> next = p;
   p -> next = NULL;

}

//----------------------------------------//



//-------------- Iterative ---------------//

void reverseIterative()
{
	node *current, *next, *prev;

	current = head;
   prev = NULL;

   while(current != NULL)
   {
   	next = current -> next;
      current -> next = prev;
      prev = current;
   	current = next;
   }

   /*
   	by the end of this loop, we will have,
   		current = NULL;
   		next = NULL;
   		prev = last node;

   	so now point the head to the last node which is now first node in reversed linked list
	*/

   head = prev;
}

//----------------------------------------//




node* getNewNode(int data)
{
    node *newNode = new node;
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

void insertAtBeginning(int data)
{
    node *newNode = getNewNode(data);
    if(head == NULL)
    {
        head = newNode;
        return;
    }

newNode -> next = head;
head = newNode;
}

void insertAtEnd(int data)
{
    node *newNode = getNewNode(data);
    if(head == NULL)
    {
        head = newNode;
        return;
    }

    node *temp = head;
    while( temp -> next != NULL)
    {
        temp = temp -> next;
    }

    temp -> next = newNode;
}

void Delete(int data)
{
    if(head == NULL)
    {
        return;
    }

    node* temp = head;

    if(head -> data == data)
    {
    		head = head -> next;
    		delete (temp);
    		return;
    }


    while(temp -> next -> data != data) //it takes to a node before the node to be deleted.
    {
        temp = temp -> next;
    }

    node *temp2 = temp -> next;
    temp -> next = temp2 -> next;
    delete(temp2);
}


void forwardPrint(node *head)
{
    cout<<"Forward...\n\t head -> " ;
    if(head == NULL)
        return;

    node *temp = head;
    while(temp != NULL)
    {
        cout<<"|"<<temp -> data<<"| -> ";
        temp = temp -> next;

    }
    cout<<"NULL";
}

void main()
{

head = NULL;

insertAtBeginning(9); cout<<endl; forwardPrint(head);
insertAtBeginning(5); cout<<endl; forwardPrint(head);
insertAtBeginning(-1); cout<<endl; forwardPrint(head);
insertAtBeginning(7); cout<<endl; forwardPrint(head);
insertAtBeginning(2); cout<<endl; forwardPrint(head);
insertAtEnd(8); cout<<endl; forwardPrint(head);

cout<<"\nReversing the linked list - Iterative\n";
reverseIterative();
forwardPrint(head);

cout<<"\n\nReversing the linked list - Recursive\n";
reverseRecursive(head);
forwardPrint(head);



Delete(-1);
cout<<"\n\nAfter deleting -1 ...\n";
forwardPrint(head);

Delete( 9);
cout<<"\nAfter deleting 9 ...\n";
forwardPrint(head);

Delete(8);
cout<<"\nAfter deleting 8 ...\n";
forwardPrint(head);

Delete(7);
cout<<"\nAfter deleting 7 ...\n";
forwardPrint(head);

getch();
}
