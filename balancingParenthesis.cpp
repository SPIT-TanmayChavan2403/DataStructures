#include <iostream>
using namespace std;

string s;
string input;
string stack[50];
int top = -1;
class balance{
	public:
	void initialize(){
		cout << endl << "Enter your string: ";
		cin >> s;
	}
	
	void push(){
		top = top + 1;
		stack[top] = ')'; 
		cout << endl << "Pushed '(' to stack" << endl;
	}
	
	void pop(){
		top = top - 1;
		cout << endl << "Popped '(' from stack " << endl;
	}
	
	public:
	string isBalanced(){
		if (s.length() == 0){
			return "Input was empty";
		}
		for (int i = 0; i <= s.length(); i++){
			if (s[i] == '('){
				push();
			} else if (s[i] == ')' ){
				if (top >= 0){
					cout << endl << " ')' encountered, removing '(' from stack" << endl;
					pop();
				} else {
					return "encounterd ')' no opening bracket found, parentheses are not balanced";
				}
			}
		}
		if (top != -1){
			return "Parentheses are not balanced, more opening parentheses found";
		} else {
			return "Parentheses are balanced";
		}
	}
};

int main(){
	balance s = balance();
	s.initialize();
	string res = s.isBalanced();
	cout<< endl << res;
	return 0;
}
