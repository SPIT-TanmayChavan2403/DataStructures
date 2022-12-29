#include <iostream>
#include <string>

using namespace std;

class Queue{
    int size, choice, front = -1, rear = -1, element;
    int stack[50];
    
    public:
        Queue(){
            cout << "Enter the size of stack: ";
            cin >> size;
            displayMenu();
        }

    private:
        void displayMenu(){
            cout << endl << "Select your choice \n 1. Enqueue \n 2. Dequeue \n 3. Display \n 4. Exit" << endl;
            cin >> choice;
            switch (choice){
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
                cout << "Enter proper choice" << endl;
                break;
            }
        }

        int isEmpty(){
            if (front == -1 && rear == -1){
                return 1;
            }
            return 0;
        }

        int isFull(){
            if ((rear + 1) % size == front){
                return 1;
            }
            return 0;
        }

        void enqueue(){
            if (isFull()){
                cout << endl  << "Overflow!" << endl;
            } else {
                if (rear == -1){
                    front = 0;
                }
                rear = (rear + 1) % size;
                cout << endl  << "Enter the number: ";
                cin >> stack[rear];
            }
            displayMenu();
        }

        void dequeue(){
            if (isEmpty()){
                cout << endl  << "Underflow!" << endl;
            } else {
                cout << endl  << "Element " << stack[front] << " removed successfully" << endl;
            }

            if (front == rear){
                front = -1;
                rear = -1;                
            } else {
                front = (front + 1) % size;
            }
            displayMenu();
        }

        void display(){
            if (isEmpty()){
                cout << endl  << "Queue is empty" << endl;
            } else {
                int i = front;
                cout<< endl ;
                while (true){
                    cout << stack[i] << " ";
                    if (i == rear){
                        break;
                    }
                    i = (i + 1) % size;
                }
                cout << endl ;
                
            }
            displayMenu();
        }
};


int main(){
    Queue q = Queue();
    return 0;
}