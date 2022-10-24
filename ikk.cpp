#include<iostream>
using namespace std;
class Quez
{
	public:
	int size;
	int rear;
	int front;
	int *q;
Quez(){
	size = 10;
	q = new int[size];
	int front = -1;
	int rear = -1;
}
bool is_empty()
{
	if(rear==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool is_full()
{
	if(rear==size-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Enqueue(int x)
{
	if(is_full())
	{
		cout<<"no space";
	}
	else
	{
		if(is_empty())
		{
			front = rear = 0;
			q[rear]= x;
		}
		else
		{
			rear++;
			q[rear]=x;
		}
		
	}
}
int Dequeue()
{
	if(is_empty())
	{
		cout<<"no value";
	}
	else
	{
		if(rear==front)
		{
			int x = q[rear];
			rear = front = -1;
			return x;
		}
		else
		{
			rear--;
			return q[rear];
		}
	}
}

void display()
{
	if(is_empty())
	{
		cout<<"Nothing to display";
	}
	else
	{
		for (int i = 0; i<=size-1 ; i++)
		{
			cout<<"The value is"<<q[i];
		}
	}
}
};
int main()
{
	int x, y, z, l;
	Quez s1;
	cin>>x;
	s1.Enqueue(x);
	cin>>y;
	s1.Enqueue(y);
	cin>>z;
	s1.Enqueue(z);
	cin>>l;
	s1.Enqueue(l);
	s1.display();
	int m = s1.Dequeue();
	cout<<m;
	s1.display();
	
}

