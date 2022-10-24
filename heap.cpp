#include<iostream>
#include <cmath>
using namespace std;
int array[50];
int n;
void insert();
void display();
void deletion();
void insert()
{
	int f;
	int parent;
	int value;
	n++;
	cout<<"Enter the value which you want to insert";
	cin>>value;
	array[n] = value;
	f = n;
	parent=floor(f/2);
	if(parent == 0)
	{
		return;
	}
	while(f>1)
		{
			if(array[parent]<array[f])
			{
				int temp = array[parent];
				array[parent]  = array[f];
				array[f] = temp;
				f = parent;
				parent=floor(f/2);
			}
			else
			{
				return;	
			}	
		}
		

	
}
int main()
{
	insert();
	display();
	
		insert();
		display();
			insert();
			display();
				insert();
				display();
					
cout<<"the heap is";
	deletion();
	display();
}
void deletion()
{
	int a = 1;
	array[1] = array[n];
	array[n] = 0;
	n--;
	
	int left_child = 2*a;
	int right_child = 2*a +1;
	
	while(a<n)
	{
		left_child = 2*a;
		right_child = 2*a +1;
	if(array[left_child]>array[right_child])
	{
		
		if(array[left_child]> array[a])
		{
			
			int temp = array[a];
			array[a] = array[left_child] ; 
			array[left_child] = temp;
			
			a = left_child;
		}
		else
		{
			return;
		}	
	}
	else if(array[left_child]<array[right_child])
	{
		if(array[right_child]> array[a])
		{
			int temp = array[a];
			array[a] = array[right_child] ; 
			array[right_child] = array[a];
			a = right_child;
		}	
		else
		{
			return;
		}
	}
	else
	{
		return;
	}
	}
	
	
	
}
void display()
{
	for(int i = 1; i < 10 ; i++)
	{
		cout<<array[i]<<"\n";
	}
}
