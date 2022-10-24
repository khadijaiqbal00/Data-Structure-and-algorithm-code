#include <iostream>
using namespace std;
int x;
int key;
void insert_end();
void insert_start();
void display();
void insert_after_specific();
void insert_before_specific();
void delet_end();
void delet_start();
void delet_after_specific();
void delet_before_specific();
struct student
{
	int id;
	float marks;
	student *next = NULL;
};
	student *first= NULL;
	student *last = NULL;
	student *search(int );
	student *k;
int main()
{
	cout<<"\nEnter 1 to insert at end \nEnter 2 to insert at start \nEnter 3 to display \nEnter 4 to insert after specific \nEnter 5 to insert before specific\t";
	cout<<"\nEnter 6 to delet at end \nEnter 7 to delet at start \nEnter 8 to delete after specific \nEnter 9 to delet before specific\t";
	cin>>x;
	while(x!=0)
	{
	switch(x)
	{
		case 1:
			insert_end();
			break;
		case 2:
			insert_start();
			break;
		case 3:
			display();
			break;
		case 4:
			insert_after_specific();
			break;
		case 5:
			insert_before_specific();
			break;
		case 6:
			delet_end();
			break;
		case 7:
			delet_start();
			break;
		case 8:
			delet_after_specific();
			break;
		case 9:
			delet_before_specific();
			break;
			
			
		default:
			cout<<"invalid";
	}
}
}
void insert_end()
{
	student *current;
	current = new student;
	cout<<"Enter the id of the student \t";
	cin>>current->id;
	cout<<"Enter the marks of the student \t";
	cin>>current->marks;
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
void insert_start()
{
	student *current;
	current = new student;
	cout<<"Enter the id of the student \t";
	cin>>current->id;
	cout<<"Enter the marks of the student \t";
	cin>>current->marks;
	if(first == NULL)
	{
		first = last = current;
	}
	else
	{
		current->next = first;
		first = current;
	}
	main();
}
void display()
{
	student *p = first;
	while(p!=NULL)
	{
		cout<<"\n The id of the student is \t";
		cout<<p->id;
		cout<<"\n The marks of the student is \t";
		cout<<p->marks;
		p=p->next;
	}
	main();
}
void insert_after_specific()
{
	cout<<"Enetr the number after which you want to insert";
	cin>>key;
	student *p = search(key);
	if(p==NULL)
	{
		cout<<"No such number exits";
	}
	else
	{
		student *current;
		current = new student;
		cout<<"Enter the id of the student \t";
		cin>>current->id;
		cout<<"Enter the marks of the student \t";
		cin>>current->marks;
		current->next = p->next;
		p->next = current;
	}
	main();
	
	
}
void insert_before_specific()
{
	cout<<"Enetr the number before which you want to insert";
	cin>>key;
	student *p = search(key);
	if(p==NULL)
	{
		cout<<"No such number exits";
	}
	else
	{
		student *current;
		current = new student;
		cout<<"Enter the id of the student \t";
		cin>>current->id;
		cout<<"Enter the marks of the student \t";
		cin>>current->marks;
		current->next = p;
		k->next = current;
	}
	main();
}
student *search(int key)
{
	student *p=first;
	while(p->id!=key && p!=NULL)
	{
		k=p;
		p=p->next;
	}
	return p;
}

void delet_end()
{
	student *del_last = first;
	student *del_2ndlast;
	if(first==NULL)
	{
		cout<<"list is empty, nothing too delet";
	}
	while(del_last!=last)
	{
		del_2ndlast = del_last;
		del_last = del_last->next;
	}
		del_2ndlast->next = NULL;
			last = del_2ndlast;
			delete (del_last);
			main();
}
void delet_start()
{
	student *del_first = first;
	if(first==NULL)
	{
		cout<<"list is empty, nothing too delet";
	}
	else
	{
		first = del_first->next;
		delete (del_first);
	}
	main();	
}
void delet_after_specific()
{
	cout<<"Enetr the number after which you want to delet";
	cin>>key;
	student *p = search(key);
	if(p==NULL)
	{
		cout<<"no such record exists";
	}
	else
	{
		student *next_node = p->next;
		if(p->next == last)
		{
			p->next = NULL;
		}
		else
		{
			
		p->next = next_node->next;
		}
		delete (next_node);
	}
	main();
}
void delet_before_specific()
{
	cout<<"Enetr the number before which you want to delete value";
	cin>>key;
	student *p = search(key);
	if(p==first)
	{
		cout<<"no previous number exists that you can delet";
		main();
	}
	if(p->next==NULL)
	{
		cout<<"No such number exits";
	}
	else
	{
		if(k==first)
		{
			first = p;
			delete(k);
		}
		else
		{
			student *z = first;
			while(z->next !=k)
			{
				z=z->next;
			}
			z->next = k->next;
			delete (k);
		}
	}
	main();
	
}
