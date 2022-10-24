
#include<iostream>
using namespace std;

#define size 100  
class stack{
	private :
	int array[size];
	int top;
	
public:
	stack()
	{
		int size;
		size=10;
		top=-1;	
	}
	bool is_full()
	{
		if(top==size-1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool is_empty()
	{
		if(top==-1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void push(int x)
	{
		if(is_full())
		{
			cout<<"\nNo space";
		}
		else
		{
			array[++top] =x; 
		}
	}
	int pop()
	{
		int x;
		if(is_empty())
		{
			cout<<"\nNothing to pop";
		}
		else
		{
			x = array[top--];
			return x;
		}
	}
	void display()
	{
		if(is_empty())
		{
			cout<<"nothing to display";
		}
		else
		{
			int f=top;
			while(f!=-1)
			{
				cout<<"\nThe value is"<<array[f];
				f--;
			}
		}
		cout<<"\n";
	}
	
	
	void palindrome()
	{
		int f =top;
		int arr[10];
		for (int i=0;i<10;i++)
		{
			arr[f]=array[i];
			f--;
		}
		// reverse --->array[f]
		f = 0;
		int n=0;
		for(int h = 0;h<top ; h++)
		{
			if(arr[f]==array[h])
			{
				f++;	
				n = 0;
			}
			
			else
			{
				
				n=1;
				break;
			}
			
		}
		if(n==1)
		{
			cout<<"\nThe entered number is not a palindrome\n";
		}
		else
		{
			cout<<"\nThe entered number is a palindrome\n";
		}	
	}
};

int main()
{
	stack s1;
	int value,i,z;
	
	while(true)
	{
		cout<<"Press 1 to push elements";
		cout<<"\nPress 2 to pop elements";
		cout<<"\npress 3 to display stack";
		cout<<"\npress 4 to check if it is palindrome or not";
		cout<<"\nEnter the value\t";
		cin>>z;
		if(z==-1)
		{
			cout<<"Successfully exit";
			break;
		}
		switch(z)
		{
			case 1:
				cout<<"\nEnter the value which you want to enter\t";
				cin>>value;
				s1.push(value);
				break;
			case 2:
				i = s1.pop();
				cout<<"\nThe value is"<<i;
				break;
			case 3:
				s1.display();
				break;
			case 4:
				s1.palindrome();
				break;
			default : 
				cout<<"invalid";
		}
	
	}
	return 0;
}
	
	
	


