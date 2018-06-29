#include<iostream.h>
#include<conio.h>

struct node
{
int data;
node *next;
} *top;

/*
void getNewNode(int data)
{
	node *newNode = new node;
   newNode -> data = data;
   newNode -> next = NULL;
   top
}
*/

void push(int data)
{
	node *newNode = new node;
	newNode -> data = data;
   newNode -> next = top;
   top = newNode;
}

void pop()
{
	if(top == NULL)
   	{
      	cout<<"\nStack underflow.";
         return;
      }

   node *temp = top;
   top = top -> next;
   delete(temp);
}

node* Top()
{
	return top;
}


bool isEmpty()
{
   if(top == NULL)
   	return true;
   else
   	return false;
}

void display()
{
	node *temp = top;
   cout<<"\tTop -> ";
   while( temp != NULL)
   {
   	cout<<"|"<< temp -> data <<"| -> ";
      temp = temp -> next;
   }
   cout<<"NULL\n";
}

int main()
{
   top = NULL; display();
   cout<<"\n Pushing 2: "; push(2); display();
   cout<<"\n Pushing 5: "; push(5); display();
   cout<<"\n Pushing 8: "; push(8); display();
   cout<<"\n Pushing 4: "; push(4); display();
   cout<<"\n Pushing 6: "; push(6); display();
   cout<<"\n Pushing 10: "; push(10); display();

   top = Top() ;
   cout<<"\nTop : "<<top<<" (address of top)"<<endl;

   cout<<"\n Pop() : "; pop(); display();
   cout<<"\n Pop() : "; pop(); display();
   cout<<"\n Pop() : "; pop(); display();
   cout<<"\n Pop() : "; pop(); display();
   cout<<"\n Pop() : "; pop(); display();
   cout<<"\n Pop() : "; pop(); display();
   cout<<"\n Pop() : "; pop(); display();

   cout<<"\n\nChecking isEmpty: ";
   isEmpty ? cout<<"Empty" : cout<<"Not empty";

	getch() ;
	return 0;
}
