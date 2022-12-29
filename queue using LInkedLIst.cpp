#include <iostream>
#include <stdlib.h>

using namespace std;

struct node{
	int data;
	struct node *next;	
} *head = NULL, *newNode, *currNode, *tempHead, *temp, *tail;

int size, currSize = 0, option, element;
class stackLL{
	public:
		void initialize(){
			cout << endl << "Please enter size for the array: ";
			cin >> size;
		}
		
		void menu(){
			do{
				cout << endl << "Select operation to perform:- \n 1: Enqueue \n 2: Dequeue \n 3: Display \n 4: Exit" << endl;
				cin >> option;
				switch(option){
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
		
		void enqueue(){
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
		
		void dequeue(){
			if (currSize == 0){
				cout << endl << "Queue undeflow, cannot pop an element" << endl;
			} else {
				if (head == tail){
					cout << endl << head->data << " removed from queue" << endl;
					currSize -= 1;
					free(head);
					head = NULL;
				} else {
					tempHead = head->next;
					cout << endl << head->data << " removed from queue" << endl;
					free(head);
					head = tempHead;
					currSize -= 1;
				}
			}
		}
		
		void display(){
			if (currSize == 0){
				cout << endl << "Queue is emtpy" << endl;
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
