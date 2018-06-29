#include <iostream.h>
#include <conio.h>


struct node
{
    int data;
    node *next;
};

node* getNewNode(int data)
{
    node *newNode = new node;
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

node* insertAtBeginning(node *head, int data)
{
    node *newNode = getNewNode(data);
    if(head == NULL)
    {
        head = newNode;
        return head;
    }

newNode -> next = head;
head = newNode;
}

node* insertAtEnd(node* head, int data)
{
    node *newNode = getNewNode(data);
    if(head == NULL)
    {
        head = newNode;
        return head;
    }

    node *temp = head;
    while( temp -> next != NULL)
    {
        temp = temp -> next;
    }

    temp -> next = newNode;
    return head;

}

node* Delete(node *head, int data)
{
    if(head == NULL)
    {
        return head;
    }

    node* temp = head;

    if(head -> data == data)
    {
    		head = head -> next;
    		delete (temp);
    		return head;
    }


    while(temp -> next -> data != data) //it takes to a node before the node to be deleted.
    {
        temp = temp -> next;
    }

    node *temp2 = temp -> next;
    temp -> next = temp2 -> next;
    delete(temp2);

    return head;

}

bool find(node *head, int data)
{
    node *temp = head;
    while(temp != NULL)
    {
        if(temp -> data == data)
        {
            return true;
        }

        temp = temp -> next;
    }

    return false;
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

void forwardPrintRecursion(node *head)
{
    if( head == NULL)       //exit condition or base case
        return;

    cout<<" "<<head -> data;
    forwardPrintRecursion(head -> next);

}


void reversePrintRecursion(node *head)
{
    if( head == NULL)       //exit condition or base case
        return;

    reversePrintRecursion(head -> next);
    cout<<" "<<head -> data;

}





void main() {

node *head = NULL;
bool found;

head = insertAtBeginning(head, 2); cout<<endl; forwardPrint(head);
head = insertAtBeginning(head, 5); cout<<endl<<"Forward Print Recursion...\n"; forwardPrintRecursion(head);
head = insertAtBeginning(head, -1); cout<<endl<<"Reverse Print Recursion...\n"; reversePrintRecursion(head);
head = insertAtBeginning(head, 7); cout<<endl; forwardPrint(head);
head = insertAtEnd(head, 8); cout<<endl; forwardPrint(head);  cout<<endl;

cout<<"\nSearching for 50 in linked list...";
found = find(head,50);
found == true? cout<<"\nElement found!\n" : cout<<"\nElement not found!\n";

cout<<"\n\nSearching for 5 in linked list...";
found = find(head,5);
found == true? cout<<"\nElement found!\n" : cout<<"\nElement not found!\n";

head = Delete(head, -1);
cout<<"\n\nAfter deleting -1 ...\n";
forwardPrint(head);

head = Delete(head, 2);
cout<<"\nAfter deleting 2 ...\n";
forwardPrint(head);

head = Delete(head, 8);
cout<<"\nAfter deleting 8 ...\n";
forwardPrint(head);

head = Delete(head, 7);
cout<<"\nAfter deleting 7 ...\n";
forwardPrint(head);

getch();
}
