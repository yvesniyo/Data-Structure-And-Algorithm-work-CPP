#include <iostream>

using namespace std;


class Node{
	
	public:
		int value;
		Node *next;
};

class List{
	
	public:
		Node *head;
		
		List(int firstValue){
			
			this->head = new Node();
			this->head->next = NULL;
			this->head->value = firstValue;
			
		}
	
	Node *lastNode(){
		
		Node *lastNode = this->head;
		
		while(lastNode->next != NULL){
			lastNode = lastNode->next;
		}
		
		return lastNode;
	}
	
	void insert(int value){
		
		Node *node = new Node();
		node->value = value;
		node->next = NULL;

		this->lastNode()->next = node;
	}
	
	void print(){
		
		cout << "List Datas: ";
		
		Node *node = this->head;
		
		while(node != NULL){
			cout << node->value;
			if(node->next != NULL) cout << ",";
			node = node->next;
		}
	}
	
	
	bool deleteItem(int data){
		
		bool deleted = false;
		
		Node *node = this->head;
		
		Node *prevNode = node;
		
		while(node != NULL){
			
			if(node->value == data){
				deleted = true;
				prevNode->next = NULL;
				break;
			}
			
			prevNode = node;
			node = node->next;
		}

		
		return deleted;
	}
	

	

		
};


int main(int argc, char** argv) {
	
	List *list = NULL;
	
	bool running = true;
	
	while(running){
		
		cout << "Choose operation: "<< endl;
		cout << "1. Insert" << endl;
		cout << "2. Display" << endl;
		cout << "3. Delete " << endl;
		cout << "4. Exit" << endl;
		
		int choice = 0;
		cin >> choice;
		
		int value;
		bool deleted  =  false;
		
		switch(choice){
			
			case 1:
				
				cout << "Enter the value: ";
				cin >> value;
				
				if(list == NULL){
					list = new List(value);
				}else{
					list->insert(value);
				}
				
				break;
				
			case 2:
				if(list != NULL){
					list->print();
				}
				
				break;
			case 3:
				
				cout << "What node data do you want to delete: ";
				cin >> value;
				
				deleted  =  false;
				deleted = list->deleteItem(value);
				
				if(deleted)
					cout << value << " Deleted in List"<< endl;
				else
					cout << value << " Could not be deleted in List"<< endl;
				
				break;
			case 4:
				running = false;
				break;
				
			default:
				cout << "Wrong choice, try again!" << endl;
				
		}
		cout << endl <<"-----------------------------"<< endl;
	}
	

	
	return 0;
}
