#include<iostream>
using namespace std;

#include<iostream>
using namespace std;
class braces{
public:
	char array[20];
	int top = -1;
	int size = 20;
	
	void push(char x)
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
		char x;
		x = array[top--];
		return x;
	
	}
	char topValue()
	{
		char d = top;
		return array[d];
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
};

int main()
{
	braces b;
	string s;
	int f;
	cout<<"Enter a string"<<endl;
	cin>>s;
	for(int i=0; i<s.length() ; i++)
	{
		if(s[i]=='(' || s[i]== '{' || s[i]== '[' )
		{
			b.push(s[i]);
		}
		else if(s[i]==')')
		{
			if(b.topValue() == '(')
			{
				b.pop();
			}
			else 
			{
				f = -1;
				break;
			}
			
		}
		else if(s[i]=='}')
		{
				f = i;
			if(b.topValue() == '{')
			{
				b.pop();
			}
			else 
			{
				f = -1;
				break;
			}
			
		}
		else if(s[i]==']')
		{
			f = i;
			if(b.topValue() == '[')
			b.pop();
			else 
			{
				f = -1;
				break;
			}
		}
		
			
	
		
	}
	if(b.is_empty() && (f!=-1 ))
	{
		cout<<"Balanced";
	}


	else if(f==-1)
	{
		cout<<"Not Balanced";
	}
	return 0;
}




