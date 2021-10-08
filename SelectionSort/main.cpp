#include <iostream>

using namespace std;

void swap(int *, int *);
void selectionSort(int[], int, bool);
void printArray(int[], int);


int main(int argc, char** argv) {
	
	
	int *array;
	int choice;
	bool running = true;
	
	cout << "Selection sort Program"<< endl;
	cout << "How many datas do you want to store: ";
	
	int capacity;
	cin >> capacity;
	
	array = new int(capacity);
	
	
	
	cout << endl;
	
	while(running){
		
		cout << "Choose the operation:"<< endl;
		cout << "1. Insert Datas "<< endl;
		cout << "2. Show Datas without sorting"<< endl;
		cout << "3. Sort Datas  Ascending"<< endl;
		cout << "4. Sort Datas  Descending"<< endl;
		cout << "5. Exit Program"<< endl;
		cin >> choice;
		
		switch(choice){

			case 1:
				cout << "Enter values: "<< endl;
				
				for(int i=0;i< capacity; i++){
					cin >> array[i];
				}
				
				cout << "Data insert completed"<< endl;
				
				break;
				
			case 2:
				
				printArray(array, capacity);
				break;
				
			case 3:
				
				selectionSort(array, capacity, true);
				printArray(array, capacity);
				break;
				
			case 4:
				selectionSort(array, capacity, false);
				printArray(array, capacity);
				break;
				
			case 5:
				running = false;
				break;
				
			default:
				
				cout << "Wrong choice, try again" ;
				
		}
		
		cout << endl << endl << "----------------------------" << endl << endl; 
	}

	return 0;
	
}

void swap(int *a, int *b){
	
	int temp = *a;
	*a = *b;
	*b = temp;
	
}


void selectionSort(int array[], int len, bool ascending){
	
	int i, j, min_idx,max_idx;
	
	
	if(ascending){
		for(j=0; j< len;j++){
		
			min_idx = j;
			
		 	for(i = j;i < len;i++){
		 		
		 		if(array[i] < array[min_idx]){
		 			min_idx = i;
				}
			}
			
			if(array[j] > array[min_idx]){
				swap(&array[j], &array[min_idx]);
			}
		}
	}else{
		
		for(j=0; j< len;j++){
		
			max_idx = j;
			
		 	for(i = j;i < len;i++){
		 		
		 		if(array[i] > array[max_idx]){
		 			max_idx = i;
				}
			}
			
			if(array[j] < array[max_idx]){
				swap(&array[j], &array[max_idx]);
			}
		}
	}
	
	
}


void printArray(int arr[], int size)
{
    int i;
    cout << " [ ";
    for (i = 0; i < size; i++){
    	cout << arr[i];
    	if(i != size-1) cout << ",";
	}
        
    cout << " ]" << endl;
}

