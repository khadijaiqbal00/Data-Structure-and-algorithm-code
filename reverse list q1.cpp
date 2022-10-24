#include<iostream>
using namespace std;
void insert_end();
void display();
void PrintRR(struct list *);
int x;
char c;
struct list
{
	int id;
	list *next=NULL;
};
	list *first = NULL; //points the first node of the linked list 
	list *last = NULL; //points the last node of the linked list
int main()
{
	do
	{
		cout<<"\nEnter 1 to insert at end \nEnter 2 to display \nEnter 3 to revevrse display \n";
		cout<<"----------------------------------";
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
				PrintRR(first);
				break;
			default:
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
	if(first == NULL) //if no node exits
	{
		first = last = current; //first and last points the same node
	}
	else // if node alredy exists
	{
		last->next = current; // current node is inserted at end
		last = current;
	} 
}
void display()
{
	list *p = first;
	cout<<"----------------------------------";
	//while loop is executed till p reaches the end of the linked list
	while(p!=NULL)
	{
		cout<<"\n The id is \t";
		cout<<p->id; // ID of every node is printed.
		p=p->next;
	}
	cout<<"\n----------------------------------";
}
void PrintRR(struct list *first)
{
	if(first==NULL)
	{
		return ;
	}
	PrintRR(first->next);
	cout<<"\n The id is \t";
	cout<<first->id;
	
}
/*
void PrintRI(struct list *)
{
	/*
					-------------MAIN LOGIC-------
	we have to print singly linked list in reverse order.
	1. Take 3 pointers
		s will point the first node
		n will point the last node
		m will point the 2nd last node
	2. Firstly the value of n is printed.
	3. Then n will move to its previous node and its value is printed.
	4. The process continues until n reaches the start of the node.
	5. The value of first node is printed at the end.
			    	-------------END-------------
	*/
	/*
	list *s;
	list *n; 
	list *m;
	if(first==NULL) 
	{
		cout<<"\nNo record to display";
	}
	else
		{
			cout<<"The reversed linked list is";
			n=last;    
			while(n!=first) 
			{
				s=first;
				// s moves to the first and it then finds the 2nd lalst value of n and store that in m
				while (s !=n ) 
				{
					m=s;
					s=s->next; 
				}
			cout<<"\n The id is \t"<<n->id; 
			n=m;// n now points the 2nd last value
			// n is moved to the previous node and the same process is executed until n reaches the start of the node 
			}
		cout<<"\n The id is \t"<<n->id; // the very first value of the list is displayed at the end
		cout<<"\n----------------------------------";
		}
	}
	
		*/
