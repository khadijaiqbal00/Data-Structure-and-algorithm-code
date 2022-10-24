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
};

int main()
{
	braces b;
	string s;
	cout<<"Enter a string"<<endl;
	cin>>s;
	for(int i=0; i<s.length() ; i++)
	{
		if(s[i]=='(')
		{
			b.push(s[i]);
		}
		else if(s[i]==')')
		{
			b.pop();
		}
	}
	if(b.is_empty())
	{
		cout<<"Balanced";
	}
	else{
		cout<<"Not Balanced";
	}
}

