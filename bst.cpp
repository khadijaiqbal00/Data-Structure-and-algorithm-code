#include<iostream>
using namespace std;
struct BST
{
	int id;
	BST *right = NULL;
	BST *left = NULL;
};
BST *root = NULL; 
void insert()
{
	BST *current = new BST;
	cout<<"Enter the value which you want to insert";
	int value;
	cin>>value;
	current->id = value;
	if(root == NULL)
	{
		root = current;
	}
	else
	{
		BST *p = root;
		BST *k = p;
		while(p!=NULL)
		{
			if(current->id>root->id)
			{
				k = p;
				p = p->right;
			}
			else
			{
				k = p;
				p = p->left;
			}	
		}
		if(current->id>k->id)
		{
			k->right = current;
		}
		else if(current->id<k->id)
		{
			k->left = current;
		}
	}
}
void inorder(BST *t)
{
	if(t == NULL)
        {
        	return;
		}
	inorder(t->left);
	cout<<t->id<<"  ";
	inorder(t->right);
}
void display()
{
	inorder(root);	
}
int main()
{
	insert();
	insert();
	insert();
	insert();
	insert();
	cout<<"root is"<<root->id;
	display();
	insert();
	insert();
	insert();
	insert();
	insert();
	cout<<"root is"<<root->id;
	display();
}
