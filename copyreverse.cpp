#include<iostream>
using namespace std;
void insert_end();
void display();
void copyReverse();
int x;
char c;
struct list
{
	int id;
	list *next=NULL;
};
	list *first = NULL;
	list *last = NULL;
int main()
{	
	do
	{
		cout<<"\nEnter 1 to insert at end \nEnter 2 to display \nEnter 3 to revevrse display \nEnter 0 to exit";
		cout<<"\n----------------------------------";
		cout<<"\nThe number entered by user is \t";
		cin>>x;
		switch(x)
		{
			case 1:
				insert_end();
				break;
			case 2:
				display();
				break;
			case 3:
				copyReverse();
				break;
			default:
				cout<<"invalid";
		}
		cout<<"\nDo you want to continue? y/n ";
		cin>>c;
	}
	while(x!=0 && c=='y' || c=='Y');
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
}
void copyReverse()
{
	
	/*
			---------------------MAIN LOGIC-----------------
	----Addresses of nodes and values with remain same but they will change the location-----
	1. Take 3 pointers.
			k points the first node 
			p points the last node
			z points the 2nd last node of p
	2. The values of k and p are swapped. and k is moved to its next while p is moved to its previous.
	4. ODD NUMBER OF NODES 
			in this case at the end p and k will point the same node and loop will break.
	5. EVEN NUMBER OF NODES 
			at the last step the next of k is p, their values will be swapped, p of next contain k , here the loop will break;
	
	*/
	list *k = first;
	list *p = last;
	list *z = first;
	list *s;
	list *f = first;
	list *n;

	if(first==NULL)
	{
		cout<<"\n No record to display";
	}
	else
	{
		cout<<"hi";
		while(k!=p && p->next!=k)
		{
			
			z = first;
			while(z->next != p)
			{
				z= z->next;
			}		
			int temp;
			temp  = k->id;
			k->id = p->id;
			p->id = temp;
			k = k->next;
			p = z;
		}
	}
	display();
	}
	
