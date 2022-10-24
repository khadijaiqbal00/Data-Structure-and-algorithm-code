# include<iostream>
using namespace std;
int size = 3;
string array[3];
int front = -1;
int rear = -1;

bool is_empty(){
	if ( front==-1 && rear == -1 ){
		return true;
	}
	else{
		return false;
	}
}

bool is_full(){
	if ( front == ((rear+1)%size))
		return true;
	
	else
		return false;
	
}

void enqueue(string x){
	
	if (is_full()){
		cout<<"No more space left for orders"<<endl;
	}
	else{
		if (is_empty()){
			rear = front = 0;
			array[rear] = x;
		}
		else{
			rear = (rear+1)%size;
			array[rear] = x;
		}
	}
}

void dequeue(){
	string order;
	if (is_empty()){
		cout<<"No order"<<endl;
	}
	else{
		order = array[front];
		if(rear == front){
			rear = front = -1;
		}
		else{
			front = (front +1)%size;
		}
	}
	cout<<order<<endl;
}

int main(){
	int value;
	do{
		cout<<"Enter 1 to serve order \nEnter 2 to place order \nEnter 0 to Exit"<<endl;
		cin>>value;
		
		switch(value){
			case 1:
				dequeue();
				break;
				
			case 2:
				string order;
				cout<<"place your order: "<<endl;
				cin>>order;
				enqueue(order);
				break; 	

				
		}
	}
	while(value != 0);
	
}
