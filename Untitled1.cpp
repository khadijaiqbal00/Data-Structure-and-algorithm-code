#include<iostream>
using namespace std;
class palindrome{
public:
	char stack[20];
	int top=-1;
	int size=20;

	void push(char x){
	if(top==size-1){
		cout<<"no space "<<endl;
	}
	else{
		top++;
		stack[top]=x;
	}
	}
	char pop(){
	{
		
		char c;
		c=stack[top];
		top--;
		return c;
	}
}
	void display(){
	cout<<"value in stack are"<<endl;
	for(int i=top;i>=0;i--){
	cout<<stack[i]<<endl;
	}
}
bool isempty(){
		if (top==-1){
			return true;
		}
		else
		return false;
		
	}
};
int main(){
	int count=-1;
	palindrome s;
	string a;
	cout<<"enter your string"<<endl;
	cin>>a;
	for (int i=0;i<a.length();i++){
		if(a[i]=='('){
		s.push(a[i]);
		}
		if(a[i]==')'){
		s.pop();
		}
		
	}
if(s.isempty()){
	cout<<"balanced"<<endl;
}
else 
cout<<"not balanced";
}
