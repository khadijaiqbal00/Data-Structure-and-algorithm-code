#include<iostream>
using namespace std;
void insert_end();
void display();
void copyreverse();
int x;
struct list
{
	int id;
	list *next=NULL;
};
	list *first = NULL;
	list *last = NULL;
int main()
{
	cout<<"\nEnter 1 to insert at end \n Enter 2 to display \n Enter 3 to revevrse display \n";
	cin>>x;
	do
	{
		switch(x)
	{
		case 1:
			insert_end();
			break;
		case 2:
			display();
			break;
		case 3:
			copyreverse();
			break;
		default:
			cout<<"invalid";
			break;
	}
	}
	while(x!=0);
}
void insert_end()
{
	list *current;
	current = new list;
	cout<<"Enter the id \t";
	cin>>current->id;
	if(first == NULL)
	{
		first = last = current;
	}
	else
	{
		last->next = current;
		last = current;
	}
	main();
}
void display()
{
	list *p = first;
	while(p!=NULL)
	{
		cout<<"\n The id is \t";
		cout<<p->id;
		p=p->next;
	}
	main();
}
void copyreverse()
{
	/*
				--------------------MAIN LOGIC--------------------
	---------------------VALUES OF THE NODES ARE SWAPPED-----------------
	1. Take 6 pointers.
			l , k points the first node of the list
			p points the last node
			z points the 2nd last node to p
		
		
	2. To swap the value first and last node of the list an integer variable temp is used
	3. After swapping the first and last values
			k moves to its next pointer
			p moves to its previous pointer
			
	
	
	
	
	
	
	
	
	*/
list *l = first;
list *k = first;
list *p = last;
list *z ;
list *s;
list *f;
while(k!=p)
{
	z = first;
	while(z->next!=p )
	{
		z = z->next;
	}
	
	if(k==first && p==last || k!=first && p!= last)
	{
		int temp ;
		temp = k->id;
		k->id = p->id;
		p->id = temp;
		k = k->next;
		p = z;
		if(k->next == z || z->next == p)
		{
			break;
		}
	}
main();
}
}
