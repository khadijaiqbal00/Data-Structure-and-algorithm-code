#include<iostream>
using namespace std;
void display();

struct BST{
	int id;
	BST *right = NULL;
	BST *left = NULL;
};
BST *root = NULL;
void insert(int , BST *);
void inorder(BST *);

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
		cout << t->id << " ";
        inorder(t->left);
        inorder(t->right);
}
BST *search(int key)
{
	BST *p = root;
	while(p->id!=key && p!=NULL)
	{
		if(p->id<key)
		{
			p = p->right;
		}
		else
		{
			p = p->left;
		}
	}
	return p;
}

void deletion()
{
	cout<<"Enter the value which you want to delet";
	int f;
	cin>>f;
	BST *w;
	BST *q = search(f);
	if(q == NULL)
	{
		cout<<"\nValue not found";
	}
	else
	{
		BST *z = root;
		w = z;
		while(z->id!=q->id && z!=NULL) // finding the 2nd last of the node which we want to delete
		{
			if(z->id<q->id)
			{
				w = z;
				z = z->right;
			}
			else
			{
				w = z;
				z = z->left;
			}	
		}
	}
	if(q->left == NULL && q->right == NULL) //DELETING LEAF NODE
	{
		if(w->left == q )
		{
			w->left = NULL;
			delete(q);
		}
		if(w->right == q )
		{
			w->right = NULL;
			delete(q);
		}
	}
	else if(q->left == NULL || q->right == NULL) //DELETING NODE HAVING ONE CHILD
	{
		if(w->right == q)
		{
			if(q->right!=NULL)
			{
				w->right = q->right;
				delete(q);
			}
			else
			{
				w->right = q->left; 
				delete(q);
			}
		}
		if(w->left == q)
		{
			if(q->left!=NULL)
			{
				w->left = q->left;
				delete(q);
			}
			else
			{
				w->left = q->right;
				delete(q);
			}
		}
		
	}
	else if(q->left != NULL && q->right != NULL) //DELETING NODE HAVING TWO CHILD
	{
		BST *q2 = q;
		BST *f = q;
		q2 = q2->right;
		while(q2->left!=NULL)
		{
			f = q2;
			q2 = q2->left;
		}
		q->id = q2->id;
		if(q2->right!=NULL)
		{
			f->left = q2->right;
			delete(q2);
		}
		else
		{
			f->left= NULL;
			delete(q2);			
		}	
	}
}
int main()
{
	for(int i = 0 ; i<12 ; i++)
	{
		int value;
		cin>>value;
		insert(value , root);
	}
	
	display();
	deletion();
	cout<<"------------------";
	display();
	deletion();
	cout<<"------------------";
	display();
	deletion();
	cout<<"------------------";
	display();
}

