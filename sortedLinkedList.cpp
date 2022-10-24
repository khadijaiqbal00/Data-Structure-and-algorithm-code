#include<iostream>
using namespace std;
void insert();
void display();
int x;
char c;
struct list
{
	int id;
	list *next = NULL;
};
	list *first = NULL;
	list *last = NULL;
	
int main()
{
	
	do
	{
		cout<<"\nEnter 1 to insert at end \nEnter 2 to dispaly ";
		cout<<"\n----------------------------------";
		cout<<"\nThe number entered by user is \t";
		cin>>x;
		switch(x)
		{
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
			default:
				cout<<"invalid";
		}
		cout<<"\nDo you want to continue? y/n ";
		cin>>c;
	}
	while(x!=0  && c=='y' || c=='Y');
}
void insert()
{
	/*
		---------------MAIN LOGIC--------------
		1. checks if the list is empty
					YES ------newly entered node is inserted
					NO
			Checks if only one value exists or more than one
					yes --- 
						if current value is less than the existing value-----node in inserted at start.
						else if current value is greater than the existing value ------node inserted at end
					NO
						newly entered value is compared in list , if it is less than any value it is inserted before that value.
	*/
	
	
	list *current;
	current = new list;
	cout<<"Enter the id \t";
	cin>>current->id;
	list *p;
	p = first;
	if(first == NULL) // if no list exits
	{
		first = last = current;
	}
	else
	{	
		if(first == last)	// if only one value exists
		{
			if (current->id > first->id)
			{
				last->next = current;
				last = current;
			}
			else if(current->id < first->id)
			{
				current->next = first;
				first = current;	
			}
		}
		else if(first!=last)
		{
			list *f ;
			f = first;
			int x = current->id;
			// x shows the value of newly entered node, loop will break at the point p is greater than x 
			// when p is greater than x , p and its previous is determined 
			while(x>p->id && p->next!=NULL)
			{
				f = p;
				p= p->next;
			}
			// if new id is less than the first value it is inserted first
			if(current->id < first->id)
			{
				current->next = first;
				first = current;	
			}
			
			else if(x>p->id)// p is less than x , x is inserted after  p
			{
				p->next = current;
				current ->next = NULL;
			}
			// else if p is greater than x , x is inserted before p
			else if(x<p->id)
			{
				f->next = current;
				current->next = p;
			}	
		}	
	}
}

void display()
{
	list *p = first;
	cout<<"\n----------------------------------";
	if(p==NULL)
	{
		cout<<"No record to display";
		
	}
	else 
	{
		while(p!=NULL)
		{
			cout<<"\n The id is \t";
			cout<<p->id;
			p=p->next;
		}
	}
	cout<<"\n----------------------------------";
	
}

