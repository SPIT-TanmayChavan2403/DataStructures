#include <iostream>

using namespace std;

struct node{
    int data;
    struct node *next;
} *head = NULL, *newNode, *currNode, *temp, *prevNode, *fp, *sp;

int choice, element, key, tempVal;
class LinkedList{
    public:
        void menu(){
            do{
                cout << endl << "Select option of your choice\n 1. Insert at front\n 2. Insert at end\n 3. Insert before an element\n 4. Insert after an element\n 5. Display\n 6. Delete element from front\n 7. Delete an element\n 8. Delete element from end\n 9. Sort\n 10. Count\n 11. Search\n 12. Exit" << endl;
                cin >> choice;
                switch(choice){
					case 1:
						insertAtFront();
						break;
					case 2:
						insertAtEnd();
						break;
					case 3:
						insertBeforeEle();
						break;
					case 4:
						insertAfterEle();
						break;
					case 5:
						display();
						break;
					case 6:
						deleteFromFront();
						break;
					case 7:
						deleteAnElement();
						break;
					case 8:
						deleteFromEnd();
						break;
					case 9:
						sort();
						break;
					case 10:
						count();
						break;
					case 11:
						search();
						break;
					case 12:
						break;
					default:
						cout << "Please enter valid choice" << endl;
						break;
				}
            }while(choice != 12);
        }

    private:
        node* takeEleFromUser(){
			cout << endl << "Enter element you want to insert: ";
			cin >> element;
			temp = (struct node *)malloc(sizeof(node));
			temp->data = element;
			temp->next = NULL;
			return temp;
		}

        void insertAtFront(){
            newNode = takeEleFromUser();
            if (head == NULL){
                head = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
        }

		void insertAtEnd(){
			newNode = takeEleFromUser();
			if (head == NULL){
				head = newNode;
			} else {
				currNode = head;
				while (currNode->next != NULL){
					currNode = currNode->next;
				}
				currNode->next = newNode;
			}
		}

		void insertBeforeEle(){
			newNode = takeEleFromUser();
			if (head == NULL){
				cout << endl << "List is empty" << endl;
			} else {
				currNode = head;
				prevNode = NULL;
				cout << endl<< "Enter the key: ";
				cin >> key;
				while (currNode->next != NULL && currNode->data != key){
					prevNode = currNode;
					currNode = currNode->next;
				}
				if (currNode->data == key && prevNode == NULL){
					newNode->next = head;
					head = newNode;
				} else if (currNode->data == key){
					prevNode->next = newNode;
					newNode->next = currNode;
				} else {
					cout << endl << "Key element not found" << endl;
				}
			}
		}

		void insertAfterEle(){
			newNode = takeEleFromUser();
			if (head == NULL){
				cout << endl << "List is empty" << endl;
			} else {
				cout << endl<< "Enter the key: ";
				cin >> key;
				currNode = head;
				while (currNode->next != NULL && currNode->data != key){
					currNode = currNode->next;
				}
				if (currNode->data == key && currNode->next == NULL){
					currNode->next = newNode;
				} else if (currNode->data == key){
					temp = currNode->next;
					currNode->next = newNode;
					newNode->next = temp;
					free(temp);
				} else{
					cout << endl << "Key element not found" << endl;
				}
			}
		}

		void deleteFromFront(){
			if(head == NULL){
				cout << endl << "List is empty" << endl;
			} else if (head->next == NULL) {
				cout << endl << head->data << " element is deleted" << endl;			
				free(head);
				head = NULL;
			} else {
				temp = head;
				head = head->next;
				cout << endl << temp->data << " element is deleted" << endl;
				free(temp);
			}
		}

		void deleteAnElement(){
			if(head == NULL){
				cout << endl << "List is empty" << endl;
			} else{
				cout << endl<< "Enter the element: ";
				cin >> key;
				prevNode = NULL;
				currNode = head;
				if (currNode->next == NULL){ // If we have only one element in list.
					if (currNode->data == key){
						cout << endl << head->data << " element is deleted" << endl;			
						free(head);
						head = NULL;
					} else {
						cout << endl << "element not found" << endl;
					}
					
				} else{
					while (currNode->next != NULL && currNode->data != key){
						prevNode = currNode;
						currNode = currNode->next;
					}
					if (prevNode == NULL && currNode->data == key){
						cout << endl << head->data << " element is deleted" << endl;
						temp = head;
						head = head->next;
						free(temp);
					}
					else if (currNode->data == key){
						prevNode->next = currNode->next;
						cout << endl << currNode->data << " element is deleted" << endl;			
						free(currNode);
					} else {
						cout << endl <<"Element not found in Linked list" << endl;
					}
				}
				
			}
		}

		void deleteFromEnd(){
			if(head == NULL){
				cout << endl << "List is empty" << endl;
			} else {
				if (head->next == NULL){
					cout << endl << head->data << " element is deleted" << endl;			
					free(head);
					head = NULL;
				} else{
					prevNode = NULL;
					currNode = head;
					while (currNode->next != NULL){
						prevNode = currNode;
						currNode = currNode->next;
					}
					cout << endl << currNode->data << " element is deleted" << endl;			
					prevNode->next = NULL;
					free(currNode);
				}
			}
		}

		void sort(){
			if (head == NULL){
				cout << endl << "List is empty" << endl;
			} else {
				if (head->next == NULL){
					display();
				} else {
					fp = head;
					while (fp != NULL){
						sp = fp->next;
						while (sp != NULL){
							if (sp->data < fp->data){
								tempVal = sp->data;
								sp->data = fp->data;
								fp->data = tempVal;
							}
							sp = sp->next;
						}
						fp = fp->next;
					}
					cout << endl << "Sorted data is: " << endl;
					display();
				}
			}
		}

		void count(){
			int count = 0;
			currNode = head;
			while (currNode != NULL){
				count++;
				currNode = currNode->next;
			}
			cout << endl << "Count is " << count << endl;
		}

		void search(){
			cout << endl << "Enter an element you want to search: ";
			cin >> element;
			currNode = head;
			while (currNode != NULL && currNode->data != element){
				currNode = currNode->next;
			}
			if(currNode == NULL){
				cout << endl << element << " not found in linked list" << endl;
			} else {
				cout << endl << element << " found in linked list" << endl;	
			}
		}

		void display(){
			if (head == NULL){
				cout << endl << "List is empty" << endl;
			} else {
				currNode = head;
				while (currNode != NULL){
					cout << currNode->data << "----->";
					currNode = currNode->next;
				};
			}
		}
};


int main(){
    LinkedList l = LinkedList();
    l.menu();
}












