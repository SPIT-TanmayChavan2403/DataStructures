#include <iostream>
#include <string>
using namespace std;

int choice, element, Q[50], removed_element, size;
int rear = -1, front = -1;


class queue{
	public:
		void initialize(){
			cout << "Please enter queue size: ";
			cin >> size;
		}

	public:		
		void menu(){
			do{
				cout << endl << "Select your choice \n 1. Insert \n 2. Delete \n 3. Display \n 4. Exit" << endl;
				cin >> choice;
				switch(choice){
					case 1:
						enqueue();
						break;
					case 2:
						dequeue();
						break;
					case 3:
						display();
						break;
					case 4:
						break;
					default:
						cout  << endl << "Please enter proper choice"  << endl;
				}
			} while (choice != 4);
		}
		
		
		void enqueue(){
			if (rear == -1) front = 0;
			
			if (rear == size-1){ // Overflow check
				cout << endl << "Overflow!" << endl;
			} else{
				rear += 1;
				cout << endl << "Enter element you want to insert: ";
				cin >> element;
				Q[rear] = element;
				cout  << endl << "Element " << element << " inserted successfully"  << endl;
			}
			
		}
		
		void dequeue(){
			if (front == -1 || front > rear){ // Underflow condition
				cout << endl << "Underflow!" << endl;
			} else {
				removed_element = Q[front];
				front += 1;
				cout << endl << "Element " << removed_element << " removed successfully" << endl;
			}
		}
		
		void display(){
			if (front > rear){
				cout << endl << "Queue is empty!" << endl;
			}
			for (int i = front; i <= rear; i ++){
				cout << Q[i] << " ";
			}
		}
};

int main(){
	queue q = queue();
	q.initialize();
	q.menu();
}




//Linear queue using array
//Circular queue using array
//Doubly ended queue 
