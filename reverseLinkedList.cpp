#include<iostream>
using namespace std;
void insert_end();
void display();
void reverseLinkedlist();
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
				reverseLinkedlist();
				break;
			default:
				cout<<"invalid";
				break;
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
	cout<<"\n----------------------------------";
	while(p!=NULL)
	{
		cout<<"\n The id is \t";
		cout<<p->id;
		p=p->next;
	}
	cout<<"\n----------------------------------";
}
void reverseLinkedlist()
{	
	/*
			---------------------MAIN LOGIC-----------------
	----Addresses of nodes and values with remain same but they will change the location-----
	1. Take 6 pointers.
			k points the first node 
			s points the next of k
			f points the previous of k
			p points the last node
			z points the 2nd last node of p
			n points the next of p
	2. firstly we will change location of first and last node
	3. When location of nodes are swapped then we will also change the first and the last pointer of the list.
	         k moves to its next node and p moves to its previous node
	4. ODD NUMBER OF NODES 
			in this case at the end p and k will point the same node and loop will break.
	5. EVEN NUMBER OF NODES 
			at the last step the next of k is p, their location will be swapped, p of next contain k , here the loop will break;
	
	*/
	


// k is not equal to p ---> for odd number of nodes
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
	while(k!=p && p->next!=k)
	{
	
		z = first;
		while(z->next!=p )//previous of p is determined
		{
			z = z->next;
		}
		s = k->next;
		if(k==first && p==last)// swapping the first and the last node
		{ 
			p->next = k->next ;
			z->next = k;
			k->next = NULL;
			first = p;
			last = k;
			k = s;
			f = p;
			p = z;
		}
		else if(k->next == p) // executed if even number of nodes
		{
			n = p->next;
			f->next = p;
			p->next = k;
			k->next = n;
		}
		else if(k!=first && p!= last ) 
		{
			s= k->next;
			z->next = k;
			f->next = p;
			k->next = p->next;
			p->next = s;
			f = p;
			k = f->next;
			p=z;
		}
	}
display();
}
}
