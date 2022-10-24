#include<iostream>
using namespace std;
void display();

struct BST{
	int id;
	BST *right = NULL;
	BST *left = NULL;
	int height = 0 ;
};
BST *root = NULL;
void insert(int , BST *);
void inorder(BST *);
int BalanceFactor(struct BST *);

void insert( int value, BST * p)
{
	BST *curr = new BST;
	curr->id = value;
	if(root == NULL)
	{
		root = curr;
	}
	else
	{
		curr->height = curr->height+1;
		if(p->id<curr->id)
		{
			if(p->right == NULL)
			{
				p->right = curr;
			}
			else 
			{
				p = p->right;
				insert(value, p);
			}
		}
		else
		{
		
			if(p->left == NULL)
			{
				p->left = curr;
			}
			else
			{
				p = p->left;
				insert(value, p);
			}
		}
	}
}
void display() {
        inorder(root);
        cout << endl;
    }
void inorder(BST* t) 
{
        if(t == NULL)
        {
        	return;
		}
		cout << " \nthe number is "<< t->id ;
		cout << "  the height is" << t->height ;
		int i = BalanceFactor(t);
		cout << " bf is " <<i ;
        inorder(t->left);
        inorder(t->right);
}
int BalanceFactor(struct BST *k)
{
	//Height of left - height of right
	return ( (k->left->height)- (k->right->height) );
}
int main()
{
	for(int i = 0 ; i<3 ; i++)
	{
		int value;
		cin>>value;
		insert(value , root);
	}
	
	display();
	
}
