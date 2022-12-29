#include <iostream>
#include <stdlib.h>

using namespace std;



struct node{
	int data;
	struct node *next;	
} *head = NULL, *newNode, *currNode, *temp, *prevNode, *fp, *sp, *tail;

int size, currSize = 0, option, element;
class stackLL{
	public:
		void initialize(){
			cout << endl << "Please enter size for the array: ";
			cin >> size;
		}
		
		void menu(){
			do{
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
			}while(option != 4);
		}
	
	private:
		
		node* generateNode(){
			cout << endl << "Enter element you want to insert: ";
			cin >> element;
			temp = (struct node *)malloc(sizeof(node));
			temp->data = element;
			temp->next = NULL;
			return temp;
		}
		
		void push(){
			if (currSize == size){
				cout << endl << "Stack overflow, cannot push new element" << endl;
			} else {
				newNode = generateNode();
				if (!head){ // If linked list is empty
					head = newNode;
					tail = newNode;
				} else if (head == tail){ // meaning we are only having one element
					head->next = newNode;
					tail = newNode;
				} else {
					tail->next = newNode;
					tail = newNode;			
				}
				currSize += 1;
			}
		}
		
		void pop(){
			if (currSize == 0){
				cout << endl << "Stack undeflow, cannot pop an element" << endl;
			} else {
				if (head == tail){
					cout << endl << head->data << " popped from array" << endl;
					currSize -= 1;
					free(head);
					head = NULL;
				} else {
					currNode = head;
					while (currNode->next != tail){
						currNode = currNode->next;
					}
					currNode->next = NULL;
					cout << endl << tail->data << " popped from array" << endl;
					free(tail);
					tail = currNode;
					currSize -= 1;
				}
			}
		}
		
		void display(){
			if (!head){
				cout << endl << "Stack is emtpy" << endl;
			} else {
				currNode = head;
				while (currNode){
					cout << currNode->data << " ";
					currNode = currNode->next;
				}
				cout << endl;
			}
		}
	
	private:
		
		
};


int main(){
	stackLL s = stackLL();
	s.initialize();
	s.menu();
}
