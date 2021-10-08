#include <iostream>
#include <stdexcept>

using namespace std;



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
		
		bool isFull(){
			if(this->size == this->max - 1) return true;
			return false;
		}
		
		bool isEmpty(){
			if(this->size == -1) return true;
			return false;
		}
		
		void enqueue(int value){
			if(this->isFull()){
				throw std::invalid_argument("Queue is full");
			}
			this->size++;
			this->items[size] = value;
		}
 
		int dequeue(){
			
			if(this->isEmpty()){
				throw	std::invalid_argument("Queue is empty");
			}
			
			
			int value = this->items[0];
			int *temp = new int(this->max);
			
			for(int i=1; i <= this->size; i++){
				temp[i-1] = this->items[i];
			}
			
			for(int i=0; i < this->size; i++){
				this->items[i] = temp[i];
			}
			
			this->size--;
			
			return value;
		}
		
		int peek(){
			return this->items[0];
		}
 
		void print(){
			cout << endl << "Queue datas are:" <<endl;
			for(int i=0; i <= this->size; i++){
				cout << this->items[i];
				if(this->size != i)  cout << ",";
			}
			cout << endl << endl;
		}
};


int main(int argc, char** argv) {
	
	
	cout << "------------- Queue Programm --------- " << endl;
	cout << "Choose the capacity of Queue: ";
	
	int capacity = 0;
	cin >> capacity;
	
	cout << endl << capacity
		 <<" capacity of Queue successfuly created " 
		 << endl << endl;
	
	bool running  = true;

	Queue queue(capacity);
	
	while(running){
	
		// Menu
		cout << "Choose the Operation" << endl;
		cout << "1. Enqueue" << endl;
		cout << "2. Dequeue" << endl;
		cout << "3. Display " << endl;
		cout << "4. Peek " << endl;
		cout << "5. Quit " << endl;
		
		int choice = 0;
		cin >> choice;
	
		switch(choice){
			
			case 1:
				cout << "Enter the value " << endl;
				
				int value;
				cin >> value;
				
				try{
					queue.enqueue(value);	
				}catch (std::exception& e){ 
					std::cerr << "Exception: " << e.what() << std::endl; 
				}		
				
				break;
			case 2:
				
				try{
					
					cout << queue.dequeue() << " Value successfuly Dequeued" << endl;
					
				}catch (std::exception& e){ 
					std::cerr << "Exception: " << e.what() << std::endl; 
				}
				
				break;
			case 3:
				queue.print();
				break;
			case 4:
				try{
					cout << queue.peek() << " Value successfuly Peeked" << endl;
				}catch (std::exception& e){ 
					std::cerr << "Exception: " << e.what() << std::endl; 
				}
				break;
			case 5:
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
