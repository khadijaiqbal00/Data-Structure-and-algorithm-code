#include<iostream>
using namespace std;
void insert_end();
void display();
void recursion();
void recursivePrintRI(struct list *);
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
			recursivePrintRI(first);
			break;
		default:
			cout<<"invalid";
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
void recursivePrintRI(struct list * )
{
	list *p = first;
	if(p==NULL)
		return;
	
		recursivePrintRI(p = p->next);
		cout<<p->id;
	
	}
	//cout<<p->id;
	
	
	
/*
		
	n=last;
	while(n!=first)
	{
	p=first;
	while (s !=n)
	{
		m=s;
		s=s->next;
	}
	cout<<"\n The id is \t"<<n->id;
	n=m;
	}
	cout<<"\n The id is \t"<<n->id;
	main();
	}
	
	
	while(p!=NULL)
	{
		recursion();
		cout<<p->id;
	}
	 main();
	}
*/
