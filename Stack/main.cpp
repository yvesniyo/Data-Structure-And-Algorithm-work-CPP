#include <iostream>
#include <stdexcept>

using namespace std;


class Stack{
	
	private:
		
		int *items;
		int top,size;
		int max;
		
	public:
		
		Stack(int MAX){
			this->max = MAX;
			this->items = new int(MAX);
			this->top = -1;
			this->size = 0;
		}
	
	
	bool isFull(){
		if(this->top == this->max -1)
			return true;
		return false;
	}
	
	bool isEmpty(){
		if(this->top == -1)
			return true;
		return false;
	}
	
	
	void push(int value){
		
		if(this->isFull()){
			cout << endl << "---- Stack is Full----" << endl;
		}else{
			this->top++;
			this->items[this->top] = value;
			this->size++;
		}
		
	} 
	
	
	
	int pop(){ 
		if(this->isEmpty()){
			throw std::invalid_argument("Stack is Empty");
		}else{
			int value = this->items[top];
			top--;  
			size--;
			return value;	
		}
		
	}
	
	
	void print(){
		cout << endl << "Stack datas are:" <<endl;
		for(int i=0; i < this->size; i++){
			cout << this->items[i];
			if(this->size - 1 != i)  cout << ",";
		}
		cout << endl << endl;
	}
};

class Queue{
	private:
		int *items;
		int size;
		int max;
		
	public:
		Queue(int max){
			this->max = max;
			this->items = new int(max);
			this->size = -1;
		}
		
		void enqueue(int value){
			this->size++;
			this->items[size] = value;
		}
		
		
		bool isEmpty(){
			if(this->size == this->max - 1) return true;
			return false;
		}
		
		bool isEmpty(){
			if(this->size == -1) return true;
			return false;
		}
		
		int dequeue(){
			
			if(this->isEmpty()){
				
			}
			
			int value = this->items[0];
			int *temp = new int(this->max);
			
			for(int i=1; i < this->size; i++){
				temp[i] = this->items[i];
			}
			
			for(inte i=0; i < this->size; i++){
				this->items[i] = temp[i];
			}
			
			return value;
		}
		
		int peek(){
			return this->items[0];
		}
		
		
		void print(){
			cout << endl << "Queue datas are:" <<endl;
			for(int i=0; i < this->size; i++){
				cout << this->items[i];
				if(this->size - 1 != i)  cout << ",";
			}
			cout << endl << endl;
		}
};


int main(int argc, char** argv) {
	
	
	cout << "------------- Stack Programm --------- " << endl;
	cout << "Choose the capacity of Stack " << endl;
	
	int capacity = 0;
	cin >> capacity;
	
	cout << endl << capacity
		 <<" capacity of Stack successfuly created " 
		 << endl << endl;
	
	bool running  = true;

	Stack stack(capacity);
	
	while(running){
	
		// Menu
		cout << "Choose the Operation" << endl;
		cout << "1. Insert" << endl;
		cout << "2. Pop" << endl;
		cout << "3. Display " << endl;
		cout << "4. Quit " << endl;
		
		int choice = 0;
		cin >> choice;
	
		switch(choice){
			case 1:
				cout << "Enter the value " << endl;
				int value;
				cin >> value;
				stack.push(value);			
				break;
			case 2:
				try{
					cout << stack.pop() << " Value successfuly popped" << endl;
				}catch (std::exception& e){ 
					std::cerr << "Exception: " << e.what() << std::endl; 
				}
				
				break;
			case 3:
				stack.print();
				break;
			case 4:
				running = false;
				break;
			default:
				cout << "Wrong choice, try again";
				break;
				
		}
		cout << endl <<"---------------------------------" << endl;
		
	}
	return 0;
}
