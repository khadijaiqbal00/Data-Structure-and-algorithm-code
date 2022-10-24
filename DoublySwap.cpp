#include<iostream>
using namespace std;
int x;
char c;
void insert_end();
void display();
int first_node;
int second_node;
void swapnodes(int first, int second);
struct list1
{
	int id;
	list1 *next = NULL;
	list1 *previous = NULL;
};
list1 *first1 = NULL;
list1 *last1 = NULL;
list1 *search(int);
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
				
				cout<<"Enter the first node";
				cin>>first_node;
				cout<<"Enter the second node";
				cin>>second_node;
				swapnodes(first_node,second_node);
				break;
		}
		cout<<"\nDo you want to continue? y/n ";
		cin>>c;
	}
	while(x!=0 && c=='y' || c=='Y');
}
void insert_end()
{
	list1 *current;
	current = new list1;
	cout<<"Enter the id \t";
	cin>>current->id;
	if(first1 == NULL)
	{
		first1 = last1 = current;
	}
	else
	{
		last1->next = current;
		current->previous = last1;
		last1 = current;
	}
}
void display()
{
	cout<<"\n----------------------------------";
	list1 *p = first1;
	while(p!=NULL)
	{
		cout<<"\n The id is \t";
		cout<<p->id;
		p=p->next;
	}
	cout<<"\n----------------------------------";

}
void swapnodes(int first, int second)
{
	list1 *p;
	if(first1 == NULL)
	{
		cout<<"NO list exists";
	}
	else
	{
		
		list1 *s1 = search(first);
		if(s1->id!= first_node)
		{
			cout<<"ID 1 not found \t";
		}
		list1 *s2 = search(second);
		if(s2->id!= second_node)
		{
			cout<<"ID 2 not found";
		}
		p = s1->next;
		
		if(s1->id == first && s2->id == second )// both id's found
		{
			if(s1->id == first1->id && s2->id == last1->id ) // first and last
			{
				
				list1 *k;
				k = s2->previous;

				k->next = s1;
				s1->previous = k;
				s2 ->next = p;
				
				s2->previous  = NULL;
				s1->next = NULL;
				first1 = s2;
				last1 = s1;
				
			}
			else if(s1->id == last1->id && s2->id == first1->id) // s1 is last and s2 is first
			{
				
				p=s2->next;
				list1 *k;
				k = s1->previous;
				k->next = s2;
				s2->next = NULL;
				s1->next = p;
				s1->previous = NULL;
				first1 = s1;
				last1 = s2;
				
			}
			else if( s1->next->id == s2->id) // consecutive
			{
				list1 *k;
				k=s2->next;
				p = s1->previous ;
				p->next = s2;
				s2->previous = p;
				s2->next = s1;
				s1->previous = s2;
				s1->next = k;
				k->previous = s1;
			}
			
			else if(s1->id == first1->id &&  s2->id != last1->id) // s1 is first but s2 is not last
			{
				
				list1 *k, *f;
				k= s2->previous;
				f= s2->next;
				s1->next =f;
			    k->next = s1;
			    s1->previous = k;
				s2->next =p;
				p->previous = s2;
				s2->previous = NULL;
				last1->next = NULL;
				first1 = s2;
				
			}
			
			else if(s1->id!=first1->id && s2->id != last1->id) // both are in the list
			{
				list1 *z;
				list1 *x;
				list1 *f;
				
				f = s2->previous;
				z = s1->previous ;
				x = s2->next;
				s2->next = p;
				z->next = s2;
				p->previous = s2;
				s2->previous = z;
				s1->next = x;
				f->next = s1;
				x->previous = s1;
				s1->previous = f;
			}
		}
	}
}
list1 *search(int key)
{
	
	list1 *p=first1;
	while(p->id!=key && p->next!=NULL)
	{
		p=p->next;
	}
	return p;
}


