# include <iostream>
using namespace std;
int main();
void enqueue(string , int );
void dequeue();
int x;

struct Orders{
	Orders *next = NULL;
	string order;
	int age;

};

Orders *start = NULL;
Orders *end = NULL;


int main(){
	do{
		cout<<"Enter 1 to serve order \nEnter 2 to place order \nEnter 0 to exit \n";
		cin>>x;
		switch(x){
			case 1:
				dequeue();
				break;
			
			case 2:
				string newOrder;
				int age;
				cout<<"Place your order"<<endl;
				cin>>newOrder;
				cout<<"enter your age \n";
				cin>>age;
				enqueue(newOrder, age);
				break;
			    	
		}
	}
	while (x != 0);
}

void enqueue(string order, int age){
	
	Orders *new_order;
	new_order = new Orders;
	new_order->age = age;
	new_order->order = order;
	
	if (start == NULL){
		start = end = new_order;
	}
	
	else if (age > start->age){
		new_order->next = start;
		start = new_order;
	}
	
	else if (age < end->age){
		end->next = new_order;
		end = new_order;
	}
	
	else {
		Orders *f = start;
		Orders *previous = NULL;
		
		while (age <= f->age){
			previous = f;
			f = f->next;
		}
			previous->next = new_order;
			new_order->next = f;
	}
	
	new_order->age = age;
}

void dequeue(){
	string serve;
	if (start == NULL){
		cout<<"no order placed"<<endl;
	}
	else{
		serve = start->order;
	    start = start->next;
	    cout<<"your order is<<<<< "<<serve<<endl;
	} 
}

