#include<iostream>
using namespace std;
class InToPo{
public:
	char array[20];
	int top = -1;
	int size = 20;
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
	void push(char x)
	{
		if(is_full())
		{
			cout<<"\nNo space";
		}
		else
		{
			array[++top] = x; 
		}
	}
	char pop()
	{
		char x;
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
	

	
	
};
int main()
{
	char l;
	int i;
	InToPo q;
	cout<<"Enter the string"<<endl;
	string s;
	string k;
	cin>>s;
	for(int i=0; i<s.length(); i++)
	{
		if(q.is_empty())
		{
			if(s[i]=='-'|| s[i]=='+'|| s[i]=='/'|| s[i]=='*')
			{
				q.push(s[i]);
			}
			else 
			{
			   cout<<s[i];
			}
		}
		
		else 
		{
			if(s[i]=='/' || s[i]=='*')
			{
				
				int f = q.top;	
				while (q.array[f]== '/' || q.array[f] == '*')
				{
					f--;
					l = q.pop();
					cout<<l;
					cout<<"popped";
				}
				if(q.array[f]== '+' || q.array[f] == '-' || q.is_empty())
				{
					q.push(s[i]);	
				}
			}
			else if(s[i]=='+' || s[i]=='-')
			{
				int f = q.top;
				
				while (q.array[f]== '/' || q.array[f] == '*'|| q.array[f]== '+' || q.array[f] == '-' )
				{
				    l = q.pop();
					cout<<l;
					f--;
				}
				if(q.is_empty())
				{
					q.push(s[i]);
				}
				
			}
			else
			{
					cout<<s[i];
			}
			
		}
		
		
	}
	l = q.pop();
	cout<<l;
	
		
	}


