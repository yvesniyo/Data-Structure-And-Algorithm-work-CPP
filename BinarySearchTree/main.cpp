#include <iostream>

using namespace std;

struct Node{
	
	int data;
	struct Node * left;
	struct Node * right;
	
};

struct Node * createNode(int data){
	struct Node *node = new struct Node();
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

void insertData(Node *&root, int data){
	
	if(root == NULL){
		root = createNode(data);
	}else if(root->data > data){
		insertData(root->left, data);
	}else{
		insertData(root->right, data);
	}
	
}

void displayInOrder(Node *&root){
	
	if(root != NULL){
		displayInOrder(root->left);
		cout << root->data << " ";
		displayInOrder(root->right);
	}
}

void displayPreOrder(Node *&root){
	
	if(root != NULL){
		cout << root->data << " ";
		displayPreOrder(root->left);
		displayPreOrder(root->right);
	}
}

void displayPostOrder(Node *&root){
	
	if(root != NULL){
		displayPostOrder(root->right);
		cout << root->data << " ";
		displayPostOrder(root->left);
	}
}


std::pair<bool, int> searchTree(Node *&root, int value){
	
	if(root == NULL){
		return make_pair(false, 0);
	}else if(root->data == value){
		return make_pair(true, value);
	}else if(root->data > value){
		searchTree(root->left, value);
	}else{
		searchTree(root->right, value);
	}
}

int main(int argc, char** argv) {
	
	
	
	
	struct Node *root = NULL;
	bool running = true;
	int choice, items, itemValue;
	std::pair<bool, int> search;
	
	cout << endl
	     << "-------------BTS Program---------" << endl << endl;
	
	while(running){
		
		cout << "-----------Menu--------------" << endl;
		
		cout << "1. Insert items in Tree" << endl;
		cout << "2. Display Tree in order" << endl;
		cout << "3. Display Tree in preoder" << endl;
		cout << "4. Display Tree in postorder" << endl;
		cout << "5. Search item in Tree" << endl;
		cout << "6. Exit Program" << endl;
		
		cin >> choice;
		
		switch(choice) {
			case 1:
				cout << "How many items do you want to insert:" << endl;
				cin >> items;
				
				for(int i=0; i < items; i++){
					cin >> itemValue;
					insertData(root, itemValue);
				}
				
				cout << items << " Storing success" << endl;
				
				break;
			case 2:
				displayInOrder(root);
				break;
			case 3:
				displayPreOrder(root);
				break;
			case 4:
				displayPostOrder(root);
				break;
			case 5:
				cout << "What value do wish to find: ";
				cin >> itemValue;
				
				search = searchTree(root, itemValue);
				if(search.first){
					cout << itemValue << " Found success "<< endl;
				}else{
					cout << itemValue << " Could not be found!" << endl;
				}
				
				break;
			case 6:
				
				running = false;
				
				break;
				
			default:
				
				cout << "Wrong choice, try again!" << endl;
		}
		
		cout << endl;

	}
	
	 
	return 0;
}
