// Creating an binary search tree implementing insertion and deletion 

# include<iostream>
# include<queue>
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
node *mini = newnode(INT8_MAX);
node* get_minimum_node(node *target)
	{
		if(!target)	
			return mini;
		else
			{
				target = target->right;
				get_minimum_node(target->left);
				get_minimum_node(target->right);
				if(target->data < mini->data)
					{
						mini->data = target->data;
					}			return mini;
			}
	}

node *delteNode(node* temp,int data)
	{
		node *temp2,*min;
		if(temp == 0)
			{
				cout<<"Bst is empty ";
				return temp;
			}
		else
			{
				if(temp->data > data)
					temp->left = delteNode(temp->left,data);
				else if(temp->data <data)
					temp->right = delteNode(temp->right,data);	 
				else 
					{
						if(temp->left && temp->right)
							{
								cout<<"Deleting node has 2 children"<<endl;
								min = get_minimum_node(temp);
								cout<<"Removing "<<temp->data<<endl;
								temp->data = min->data;
								cout<<"Now new root is "<<temp->data<<endl;
								delete min;
								return temp;
							}
						else if(temp->left)
							{
								cout<<"Deleting node has left child only "<<endl;
								temp2 = temp->left;
								cout<<"Removing "<<temp->data<<endl;
								delete temp;
								return temp2;
							}
						else if(temp->right)
							{
								cout<<"Deleting node has only right child only"<<endl;
								temp2 = temp->right;
								cout<<"Removing "<<temp->data<<endl;
								delete temp;
								return temp2;
							}
						else
							{
								cout<<"Deleting node"<<temp->data<<endl;
								free(temp);
							}
					}
			}
	}
void displayTreeBFS(node *root)
	{
		cout<<"Displaying BST in level order : "<<endl;
		queue <node*> q;
		node *temp;
		q.push(root);
		while(!q.empty())
			{
				temp = q.front();
				if(temp)
					{
						cout<<temp->data<<endl;

						q.push(temp->left);
						q.push(temp->right);
					}
				q.pop();
			}
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
		displayInorder(root);
		// delteNode(root,5);
		displayInorder(root);
		return 0;
	}




	