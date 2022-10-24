#include<iostream>
using namespace std;
void insert_end();
void sortedInsertion();
void display();
int x;
int s;
struct list
{
	int data;
	list *link = NULL;
};
	list *head = NULL;
	list *last = NULL;
	
int main()
{
	cout<<"\nEnter 1 to insert at end \nEnter 2 to sorted insertion , enter 3 to display ";
	cin>>x;
	while(x!=0)
	{
	switch(x)
	{
		case 1:
			insert_end();
			break;
		case 2 :
			sortedInsertion();
			break;
		case 3:
			display();
			break;
		default:
			cout<<"invalid";
	}
}
}
void insert_end()
{
	list *current;
	current = new list;
	cout<<"Enter the id of the student \t";
	cin>>current->data;
	if(head == NULL)
	{
		head = last = current;
	}
	else
	{
		last->link = current;
		last = current;
	}
	main();
}
void sortedInsertion(){
	cout<<"enter key";
    cin>>s;
    list *temp;
    list *newP;
    newP = new list;
    
    cout<<"---------------------";
    newP -> data = s;
    newP -> link = NULL;
    
    int key = s;
    cout<<"---";
    if(head==NULL)
    {
    	head = last = newP;
	}
	else
	{
		if(head==last )
		{
			if(newP>head)
			{
			head ->link = newP;
			last = newP;	
			}
			else
			{
				newP->link = head;
				head = newP;
			}
		}
	} 	main();
		
	 if(head!=last)
		{
			cout<<"------";
			list *temp2 = head;
			temp = head;       
			while( temp ->link != NULL && temp->data < key)
			{
				temp2 = temp;
				temp = temp->link;
			}
			cout<<"----"<<temp2->data;
			cout<<"--3333--"<<temp->data;
			if(key<temp->data)
			{
				newP->link =  temp;
				temp2->link = newP;
			}
			else if( key > temp->data)
			{
				temp->link = newP;
				last = newP;
				if(temp==last)
			{
				temp->link = NULL;
			}
			}
		}
		
	

}
void display()
{
	list *p = head;
	while(p!=NULL)
	{
		cout<<"\n The id of the student is \t";
		cout<<p->data;
		p=p->link;
	}
	main();
}
	
