bool is_empty();
void push(char );
char pop();
void display();

char array[20];
int top = -1;
int size = 20;

int main()
{
	char i;
	InToPo q;
	cout<<"Enter the string"<<endl;
	string s;
	string final;
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
				k = k + s ;
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
					i = q.pop();
					k = k + i ;
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
					
					i = q.pop();
					k = k + i ;
					f--;
				}
				if(q.is_empty())
				{
					q.push(s[i]);	
				}
			}
			else
			{
					k = k + s ;
			}
			q.display();
			
			
			
		}
		
		
	}
	
		
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
		else if(s[i]==')')
		{
			char d;
			d = top;
			while(array[d]!='(' && !is_empty)
			{
				pop();
			}
		}
	}
}	
	
	
int precedece(char z)
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
		return 1
	}
	else 
	{
		return -1;
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
	

