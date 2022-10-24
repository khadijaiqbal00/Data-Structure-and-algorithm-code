// PROBLEM --->SEARCH KA MATHOD THEEK KARNA . CONSECUTIVE NODES KI CODITION DALNI

#include<iostream>
using namespace std;
void insert_end();
void display();
void swapnodes(int first, int second);
int x;
char c;
int first_node;
int second_node;
struct list
{
	int id;
	list *next = NULL;
};
list *first = NULL;
list *last = NULL;
list *search(int );
int main()
{
	do
	{
		cout<<"\nEnter 1 to insert at end \nEnter 2 to display \nEnter 3 to swap nodes ";
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
				
				cout<<"Enter the first node  :  ";
				cin>>first_node;
				cout<<"Enter the second node  :  ";
				cin>>second_node;
				swapnodes(first_node,second_node);
				break;
				
			default :
				cout<<"Invalid";
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
	cout<<"\n----------------------------------";
	list *p = first;
	while(p!=NULL)
	{
		cout<<"\n The id is \t";
		cout<<p->id;
		p=p->next;
	}
	cout<<"\n----------------------------------";
}
void swapnodes(int first1, int second1)
{
	/*
				--------------MAIN LOGIC----------
		---------addresses will remain same but location will change-------
		1. Take 2 numbers from user which you want to swap.
		2. Take 3 pointers
				p points the first node
				z points the last node
				x points the previous of s2
				
		2. Find those numbers in the list
				if NOT found 
				if found 
			s1 points the first value
			s2 points the second value
			
				-----------------4 CONDITIONS-----------
				1. s1 is at first and s2 is at last.
				2. s1 is at first but s2 is not at last
				3. s2 is at first and s1 is at last
				4. s1 is not at first and s2 is not at last
				5. s1 and s2 maybe both consecutive.
	
	
	*/
	list *x;
	list *p;
	p = first;
	list *z;
	z=last;
	x = first;
	if(first==NULL)
	{
		cout<<"NO list exists";
	}
	
	else
	{
		// first value is being searched in the list
		list *s1 = search(first1);
		if(s1->id!= first_node)
		{
			cout<<"ID 1 not found";
		}
		list *s2 = search(second1);
		if(s2->id!= second_node)
		{
			cout<<"ID 2 not found";
		}
		if(s1->id == first_node && s2->id == second_node )
		{
			if(s1->id == first->id && s2->id == last->id )// swapping first and last node
			{
				while(x->next != last)
				{
					x = x->next;
				}
				list *k;
				k = p->next;
				x->next = p;
				p->next = NULL;
				z->next = k;
				first = z;
				last = p;
			}
			else if(s1->next==s2 )// both are consecutive
			{
				p = s2->next;
				x = first;
				while(x->next != s1)
				{
					x = x->next;
				}
				x->next = s2;
				s2->next = s1;
				s1->next = p;
			}
			else if(s1->id == first->id &&  s2->id != last->id)// if s1 is first but s2 is not last
			{
				z = s2;
				while(x->next != s2)
				{
					x = x->next;
				}
				list *f;
				f = z->next;
				z->next = p->next;
				x->next = p;
				p->next = f;
				first = z;
			}
			else if(s1->id == last->id && s2->id == first->id) // if s2 is first and s1 is last
			{
			
				while(p->next!=s1)
				{
					p = p->next;
				}
				p->next = s2;
				s1->next = s2->next;
				s2->next = NULL;
				first = s1;
				last = s2;
			}
			else if(s1->id!=first->id && s2->id != last->id)// if s1 is not first and s2 is not last that is both are in middle
			{
				while(p->next !=s1)
				{
					p = p->next;
				}
				x = s2->next;
				p->next = s2;
				s2->next = s1;
				s1->next = x;
			}
	    }
	    
		
	}
	
}
list *search(int key)
{
	list *p=first;
	while(p->id!=key && p->next!=NULL)
	{
		p=p->next;
	}
	return p;
	
	
}


