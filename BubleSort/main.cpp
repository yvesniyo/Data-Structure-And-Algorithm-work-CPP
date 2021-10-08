#include <iostream>

using namespace std;

void swap(int *, int *);
void bubleSort(int[], int, bool);
void printArray(int[], int);


int main(int argc, char** argv) {
	
	
	int *array;
	int choice;
	bool running = true;
	
	cout << "Buble sort Program"<< endl;
	cout << "How many datas do you want to store: ";
	
	int capacity;
	cin >> capacity;
	
	array = new int(capacity);
	
	
	
	cout << endl;
	
	while(running){
		
		cout << "Choose the operation:"<< endl;
		cout << "1. Insert Datas"<< endl;
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
				
				bubleSort(array, capacity, true);
				printArray(array, capacity);
				break;
				
			case 4:
				bubleSort(array, capacity, false);
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


void bubleSort(int array[], int len, bool ascending){
	
	int i,j;
	bool swapped;
	for( i=0;i <len-1; i++){
		
		swapped = false;
		
		for(j =0; j < len-i-1; j++){
			
			if(ascending){
				if(array[j] > array[j+1]){
					swap(&array[j], &array[j+1]);
					swapped = true;
				}
			}else{
				if(array[j] < array[j+1]){
					swap(&array[j], &array[j+1]);
					swapped = true;
				}
			}
			
		} 
		
		if(!swapped{
			break;
		}
	}
	
}


void printArray(int arr[], int size)
{
    int i;
    cout << " [ ";
    for (i = 0; i < size; i++)
        cout << arr[i] << ",";
    cout << " ]" << endl;
}

