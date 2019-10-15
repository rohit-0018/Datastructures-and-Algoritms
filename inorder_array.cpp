# include<iostream>

using namespace std;

struct node
{	
	int data;
	node *left;
	node *right;
};
node* newnode(int data)
	{
		node * temp = new node;
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
	}

void displayInorder(node *root)
	{
		if(!root)
			return ;
		else
			{
				displayInorder(root->left);
				cout<<root->data<<endl;
				displayInorder(root->right);
			}
		
	}
node* insertNode(node *root,int value)
	{
		if(root == 0)
			{
				root = newnode(value);
				return root;
			}
		else
			{
				if(root->data > value)
					root->left = insertNode(root->left,value);
				else if(root->data < value)
					root->right = insertNode(root->right,value);
				else if (root->data == value)
			 		{
						cout<<"Already there";
						return root;
					}
			}
		return root;
	}

int main()
	{
		node *root = 0,*mini;
	
		root = insertNode(root,50);
		root = insertNode(root,10);
		root = insertNode(root,90);
		root = insertNode(root,5);
		root = insertNode(root,20);
		root = insertNode(root,60);
		root = insertNode(root,110);
		root = insertNode(root,4);
// Insertion is totally working
		inorder_array_implement(root);

		// displayInorder(root);
		return 0;
	}
