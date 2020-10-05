//					BINARY SEARCH TREE (BST)

#include<iostream>
using namespace std;

struct node 					// a BST node structure
{
	int data;					//data in the node
	node *left, *right;			//links to left subtree and right subtree
};

/*
function name: getNewNode()
input: data to be entered in the new node.
returns: address of the newly created node.
working: function to create a new node dynamically.
*/
node* getNewNode(int data)
{
	node *newNode = new node;
	newNode -> data = data;
	newNode -> left = newNode -> right = NULL;
	return newNode;
}

/*
function name: insert()
input: address of the root node and data to be inserted in the new node.
returns: address of the root node.
working: function to insert a new node in the BST.
*/
node* insert(node *root, int data)
{
	if(root == NULL)  //empty tree (base case)
	{
		root = getNewNode(data);
		return root;
	}
	else if(data <= root -> data)						//if value of 'data' is less than current node then go to left subtree (recursive call)
		root->left = insert(root -> left, data);
	else 												//if value of 'data' is greater than current node then go to right subtree (recursive call)
		root -> right = insert(root -> right, data);

	return root;
}

/*
function name: search()
input: address of the root node and value to be searched in the BST.
returns: (bool) true if value is found and false otherwise.
working: function to search a value in the BST.
*/
bool search(node *root, int data)
{
	if(root == NULL) 
		return false;
	else if(root -> data == data)
		return true;
	else if(data < root -> data)
		return search(root -> left, data);
	else 
		return search(root -> right, data);
}

int main()
{
	node* root = NULL;		// creating an empty tree

	//inserting data into the Binary search tree

	root = insert(root, 15);
	root = insert(root, 10);
	root = insert(root, 1);
	root = insert(root, 5);
	root = insert(root, 18);
	root = insert(root, 50);
	root = insert(root, 40);
	root = insert(root, 35);
	root = insert(root, 12);
	

	int searchMe = 15; // searchMe is the value we want to search in the tree.

	if( search(root, searchMe) ) 		// search for the searchMe element in the tree, return true if found and false if not found
		cout<<"\nFound";		// if statement is true
	else 
		cout<<"\nNot found";	// if statement is false 
}
