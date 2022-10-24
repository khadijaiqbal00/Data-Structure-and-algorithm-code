#include<iostream>
using namespace std;
int array[20];
int top = -1;
int size = 20;
bool is_full();
bool is_empty();
void push(int );
int pop();
void display();
bool isOperator(char );
char topValue();
bool isOperand(char );
void postfixEvaluation(string);
bool isOperand(char c)
{
	if(c>='a' && c<='z' || c>='A' && c<='z' || c>='0' &&  c<='9' )
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isOperator(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*' || c=='^')
	{
		return true;
	}
	else
	{
		return false;
	}
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
void push(int x)
	{
		if(is_full())
		{
			cout<<"\nNo space";
		}
		else
		{
			array[++top] =x; 
			cout<<x;
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
	
	
int main()
{
	string s;
	cout<<"Enter the expression";
	cin>>s;
	string evaluate;
	postfixEvaluation(s);
	display();
}


void postfixEvaluation(string s)
{
	int final;
	for(int i=0 ; i<s.length() ; i++)
	{
	     	if(isOperand(s[i]))
			{
				int z = s[i]-48;
				push(z);
				display();
			}
			else if(isOperator(s[i]))
			{
				char a = pop();
				char b = pop();
				if(s[i]=='+')
				{
					final =	b + a ;
					push(final);
					display();
				}
				if(s[i]=='-')
				{
					final =	b - a ;
					cout<<final;
					push(final);
					display();
				}
				if(s[i]=='/')
				{
					final =	b / a ;
					push(final);
					display();
				}
				if(s[i]=='*')
				{
					final =	b * a ;
					push(final);
					display();
				}
				//if(s[i]=='^')
				//{
					
				//}
				
			}
			
	}
}
