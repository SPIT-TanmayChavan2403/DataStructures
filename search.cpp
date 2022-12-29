#include <iostream>
#include <limits>

using namespace std;

int size = 0, arr[50], choice, target = 0;

class Search{
	public:
		void menu(){
			do{
				cout << endl << "Select your choice\n 1. Initialize size of array\n 2. Initialize array\n 3. Search using Linear search\n 4. Search using Binary search\n 5. Search using Binary search (Interpolation)\n 6. Exit" << endl;
				cout << endl << "Enter your choice: ";
				cin >> choice;
				switch(choice){
					case 1:
						initializeSizeOfArray();
						break;
					case 2:
						initializeArray();
						break;
					case 3:
						linearSearch();
						break;
					case 4:
						binarySearch();
					case 6:
						break;
				}	
			}while(choice != 6);
		}
	
	private:
		void initializeSizeOfArray(){
			cout << endl << "Enter size of the array: ";
			cin >> size;			
		}
		
		void initializeArray(){
			if (size == 0){ // First check if the user have initialzed size.
				cout << endl << "Please initialize the size of array first" << endl;
			} else {
				cout << endl << "Enter space seperated values for according to the size of the array which is " << size << endl;
				for (int i = 0; i < size; i++){
					cin >> arr[i];
				}
			}
			cin.clear(); // If user enters more values more than the size we will clear the input buffer.
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		}
		
		void linearSearch(){
			cout << "Enter the target element which you wanna search: ";
			cin >> target;
			bool flag = false; // Assume we dont find the target not found in the array.
			for (int i = 0; i < size; i++){
				if (arr[i] == target){
					flag = true;
					cout << endl << "Element found at position " << i + 1 << endl;
					break;
				}
			}
			if (!flag){ 
				// If flag is still false that means we did not enter "if" condition and update the flag value.
				// which indirectly means we did not find the element in the array.
				cout << endl << "Element not found in the array :(" << endl;
			}
		}
		
		void sort(){
			for (int fp = 0; fp < size - 1; fp++){
				for (int sp = fp + 1; sp < size; sp++){
					if (arr[sp] < arr[fp]){
						swap(arr[fp], arr[sp]);
					}
				}	
			}
		}
	
		void binarySearch(){
			cout << "Enter the target element which you wanna search: ";
			cin >> target;
			sort();
			bool flag = false;
			int low = 0, mid = 0, high = size - 1;
			while (low <= high){
				// calculate the  middle position
				mid = (low + high) / 2;
				if (target == arr[mid]){
					flag = true;
					cout << endl << "Element found at position " << mid + 1 << endl;
					break;
				} else if (target > arr[mid]){
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			}
			if (!flag){ 
				// If flag is still false that means we did not enter "if" condition and update the flag value.
				// which indirectly means we did not find the element in the array.
				cout << endl << "Element not found in the array :(" << endl;
			}
		}

		void display(){
			for (int i = 0; i < size; i++){
				cout << arr[i] << " ";
			}
			cout << endl;
		}
};


int main(){
	Search s = Search();
	s.menu();
}
