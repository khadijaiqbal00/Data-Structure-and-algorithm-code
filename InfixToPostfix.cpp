#include<iostream>
using namespace std;
bool is_full();
bool is_empty();
void push(char );
void pop();
void display();
char toop();
bool isOperator(char );
int precedence(char z);
string InfixToPostfix(string );

char array[20];
int top = -1;
int size = 20;

int main()
{
	string s;
	string PostfixExpression;
	cout<<"Enter the string";
	cin>>s;
	PostfixExpression = InfixToPostfix(s);
	cout<<"--";
	cout<<"The postfix Expression is"<<PostfixExpression;
	
}
	
string InfixToPostfix(string s)
{
	string final;
	for(int i=0 ; i<s.length() ; i++)
	{
		if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' && s[i]>=0 && s[i]<=9)
		{
			final = final + s[i];
		}
		else if(s[i]=='(')
		{
			push(s[i]);
		}
		else if(s[i]==')'){
			display();
			while(toop()!='('&& !is_empty()){
				final=final+toop();
				pop();
				}
				display();
				pop();
				display();
		}
		
		else if(isOperator(s[i]))
		char f;
		char f = top;
		{
			
			while(!is_empty && precedence(s[i]) <= precedence(array[f] ))
			{ 
				char z = pop();
				final = final + z; 
				z--;
			}
			push(s[i]);
		}
		
	}
	while(!is_empty())
	{
		char z = pop();
		final = final + z; 
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
int precedence(char z)
{
	if(z=='^')
	{
		return 3;
	}
	if(z=='/' || z=='*')
	{
		return 2;
	}
	if(z=='+' || z=='-')
	{
		return 1;
	}
	else 
	{
		return -1;
	}
}
char toop(){
	{
		
		char c;
		c=stack[top];
		return c;
	}
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
	void pop()
	{
		top--;
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
	

