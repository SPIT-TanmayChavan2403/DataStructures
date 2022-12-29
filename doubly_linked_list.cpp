#include <iostream>
#include <stdlib.h>

using namespace std;

struct node{
	int data;
	node* prev;
	node* next;
} *head, *tempNode, *newNode, *currNode, *prevNode, *nextNode;

int choice, element, target;
class linkedList{
	public:
		linkedList(){
			head = NULL;
		}
		void menu(){
			do{
				cout <<endl << "Select the menu from the below list\n 1. Insert (beginning)\n 2. Insert (Before)\n 3. Insert (After)\n 4. Insert (End)\n 5. Delete (beginning)\n 6. Delete (particular value)\n 7. Delete(end)\n  8. Display\n" << endl;
				cout << endl << "Enter your choice: ";
				cin >> choice;
				switch(choice){
					case 1:
						insertAtBeg();
						break;				
					case 2:
						insertBefore();
						break;
					case 3:
						insertAfter();
						break;
					case 4:
						insertAtEnd();
						break;
					case 5:
						deleteAtBeg();
						break;
					case 6:
						deleteAnEle();
						break;
					case 8:
						display();
						break;
					case 9:
						break;
					default:
						cout << "PLease enter valid input"	<< endl;
						break;
				}	
			}while(choice != 9);
		};
		
		node* generateNewNode(){
			cout << endl << "Enter element you want to insert: ";
			cin >> element;
			newNode = (struct node*)malloc(sizeof(node));
			newNode->data = element; // Setting value of node.
			return newNode;
		}
		
		void insertAtBeg(){
			
			cout << endl;
			if (head == NULL){
				newNode = generateNewNode();
				newNode->next = NULL;
				newNode->prev = NULL;
				head = newNode;
			} else{
				newNode = generateNewNode();				
				head->prev = newNode;
				newNode->next = head;
				newNode->prev = NULL;
				head = newNode;
			}
		}
		
		void insertBefore(){
			cout << "Enter key value: ";
			cin >> target;
			if (head == NULL){
				cout << endl << "LInked list is empty" << endl;
			} else {
				currNode = head;
				prevNode = NULL;
				while(currNode && currNode->data != target){
					prevNode = currNode;
					currNode = currNode->next;					
				}
				if (prevNode == NULL){ // The target element is head itself.
					newNode = generateNewNode();
					newNode->next = head;
					head->prev = newNode;
					newNode->prev = NULL;
					head = newNode;
				}
				else if (currNode && currNode->data == target){  // Checking if the key element is found
					newNode = generateNewNode();
					prevNode->next = newNode;
					newNode->next = currNode;
					newNode->prev = prevNode;
					currNode->prev = newNode;
				} else {
					cout << endl << "We did not found the key element" << endl;
				}
			}
			
		}
		
		void insertAfter(){
			cout << "Enter key value: ";
			cin >> target;
			if (head == NULL){
				cout << endl << "Linked list is empty" << endl;
			} else {
				if (head->next == NULL && head->data == target){ // If head is the only element and head is also the target element then...
					newNode = generateNewNode();
					head->next = newNode;
					newNode->prev = head;
					newNode->next = NULL;
				} else if (head->next == NULL && head->data != target){
					cout << endl << "We did not found the key element" << endl;
				} else {
					currNode = head;
					nextNode = currNode->next;
					while(nextNode && currNode->data != target){
						currNode = currNode->next;
						nextNode = currNode->next;
					}
					if (nextNode == NULL){ // If we reached at the last position.
						newNode = generateNewNode();
						if (currNode->data == target){
							currNode->next = newNode;
							newNode->prev = currNode;
							newNode->next = NULL;
						} else {
							cout << endl << "We did not found the key element" << endl;
						}
					}
					else if (currNode && currNode->data == target){  // Checking if the key element is found
						newNode = generateNewNode();
						currNode->next = newNode;
						newNode->next = nextNode;
						newNode->prev = currNode;
						nextNode->prev = newNode;
					} else {
						cout << endl << "We did not found the key element" << endl;
					}
				}
			}
		}
		
		void insertAtEnd(){
			if (head == NULL){
				cout << endl << "Linked list is empty" << endl;
			} else {
				currNode = head;
				while (currNode->next){
					currNode = currNode->next;
				}
				newNode = generateNewNode();
				currNode->next = newNode;
				newNode->prev = currNode;
				newNode->next = NULL;				
			}
		}
		
		void deleteAtBeg(){
			if (head == NULL){
				cout << endl << "Linked list is empty" << endl;
			} else {
				if (head->next == NULL){
					cout << endl << "Element " << head->data << " is delete" << endl;
					free(head);
					head = NULL;
				} else {
					tempNode = head->next;
					cout << endl << "Element " << head->data << " is delete" << endl;
					free(head);
					head = tempNode;
				}
			}
		}
		
		void deleteAnEle(){
			if (head == NULL){
				cout << endl << "Linked list is empty" << endl;
			} else {
				cout << "Enter key value: ";
				cin >> target;
				currNode = head;
				prevNode = NULL;
				
				while (currNode && currNode != target){
					prevNode = currNode;
					currNode = currNode->next;
				}
				if (prevNode == NULL){
					
				}
			}
		}
		
		void display(){
			if (head == NULL){
				cout << endl << "Linked list is empty :( " << endl;
			} else {
				currNode = head;
				do {
					cout << currNode->data << " ";
					currNode = currNode->next;
				}while(currNode);
				cout << endl;
			}
		}
		
};

int main(){
	linkedList l;
	l.menu();
	return 0;
}
