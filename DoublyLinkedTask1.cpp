#include<iostream>
using namespace std;
int x;
char c;
void insert_end1();
void insert_end2();
void display3();
struct list
{
	int id;
	list *next = NULL;
	list *previous = NULL;
};
list* intersection(struct list *, struct list *);
void display(struct list *);
list *first1 = NULL;
list *last1 = NULL;
list *first2 = NULL;
list *last2 = NULL;
list *first3 = NULL;
list *last3 = NULL;
int main()
{
	do
	{
		cout<<"\nEnter 1 to insert in one list \nEnter 2 to insert in the second list \nEnter 3 to display first list \nEnter 4 to display second list \t";
		cout<<"\nEnter 5 to compare both lists" ;
		cout<<"\n----------------------------------";
		cout<<"\nThe number entered by user is \t";
		cin>>x;
		switch(x)
		{
			case 1:
				insert_end1();
				break;
			case 2:
				insert_end2();
				break;
			case 3:
				display(first1);
				break;
			case 4:
				display(first2);
				break;
			case 5:
				list *f;
				f = intersection(first1, first2);
				display(first3);
				break;
			default:
				cout<<"invalid";
		}
		cout<<"\nDo you want to continue? y/n ";
		cin>>c;
	}
	while(x!=0 && c=='y' || c=='Y');
}

void insert_end1()
{
	list *current;
	current = new list;
	cout<<"Enter the id of the student \t";
	cin>>current->id;
	if(first1 == NULL)
	{
		first1 = last1 = current;
	}
	else
	{
		last1->next = current;
		current ->previous = last1;
		last1 = current;
	}
}
void insert_end2()
{
	list *current;
	current = new list;
	cout<<"Enter the id of the student \t";
	cin>>current->id;
	if(first2 == NULL)
	{
		first2 = last2 = current;
	}
	else
	{
		last2->next = current;
		current ->previous = last2;
		last2 = current;
	}
}
void display(struct list *f)
{
	list *p = f;
	cout<<"\n----------------------------------";
	while(p!=NULL)
	{
		cout<<"\n The id of the student is \t";
		cout<<p->id;
		p=p->next;
	}
	cout<<"\n----------------------------------";
}
list* intersection(struct list *, struct list *)
{
	/*
	----------------------MAIN LOGIC----------------
	1. Take 2 pointers
		k will point the start of list1
		p will point teh start of list2
	2. firstly we compare the id of p with all nodes of k.
			If id matches it is stored in new list and p is moved to its next.
			else p is moved to its next
	3. Loop is terminated when p of next is null that is it reaches the end of the list
	
	*/
	list *k;
	k = first1;
	list *p;
	p = first2;
	while(p !=last2 ->next )
	{
		k = first1;
		int z = p->id;
		while(k->id!=z && k->next!=NULL)
		{
			k = k->next;
		}
		if(k->id==z)
		{
			list *current3;
			current3 = new list;
			current3->id = k->id;
			if(first3 ==NULL)
			{
				first3 = last3 = current3;
			}
			else
			{
				last3->next = current3;
				current3 ->previous = last3;
				current3 ->next = NULL;
				last3 = current3;
			}
			p = p->next;
		}
		else if(k->id!=p->id)
		{
			p = p->next;
		}
	}
	return first3;
}


