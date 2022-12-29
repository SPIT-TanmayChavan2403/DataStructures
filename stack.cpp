#include <iostream>
using namespace std;

int size;
int top = -1;
int arr[50];
int element;
int popped_element, option;
class stack{
	public:
	void initialize(){
		cout << endl << "Plese enter stack size" << endl;
		cin >> size;
	}
	
	public:
	void menu(){
		cout << endl << "Select operation to perform:- \n 1: Push \n 2: Pop \n 3: Display \n 4: Exit" << endl;
		cin >> option;
		switch(option){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				break;
			default:
				cout << endl << "Exiting, as invalid input received";
				break;
		}
	}
	
	void push(){
		if (top == size-1){
			cout << endl <<"Overflow!" << endl;
		} else {
			top = top + 1;
			cout << endl << "Enter an element: ";
			cin >> element;
			arr[top] = element;
			cout << element << " is pushed successfully in stack" << endl;
		}
		menu();
	};
	
	void pop(){
		if (top == -1){
			cout << endl << "Underflow!" << endl;
		} else {
			popped_element = arr[top];
			top = top - 1;
			cout << popped_element << " is removed successfully from stack" << endl;
		}
		menu();
	}
	
	void display(){
		if (top == -1){
			cout << endl << "Stack is empty, please push some elements first" << endl;
		} else {
			for (int i = top; i >= 0; i--){
				cout << arr[i] << " ";
			}
		}
		menu();
	}
};

int main(){
	stack s = stack();
	s.initialize();
	s.menu();
	return 0;
}
