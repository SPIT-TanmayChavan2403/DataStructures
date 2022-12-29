#include <iostream>
using namespace std;


// string s = "x^y/(5*z)+2";
string s = "(( A + B ) - C * (D / E)) + F";
char stack[50];
int top = -1;
string popped_item, res, expression;
class convert{

	int precedence(char c){
		if (c == '^')
			return 3;
		else if(c == '/' || c == '*')
			return 2;
		else if (c == '+' || c== '-' )
			return 1;
		else
			return -1;
	}
	
	void push(char inp){
		top = top + 1;
		stack[top] = inp;
	}
	
	string pop(){
		popped_item = stack[top];
		top = top - 1;
		return popped_item;
	}
	
	public:
	string infixToPostfix(){
		for (int i = 0; i < s.length(); i++){
			if (s[i] == ' '){
				continue;
			}
			else if (s[i] == '('){
				push('(');
			} else if (s[i] == ')'){
				while (stack[top] != '('){
					expression += pop();
				}
				pop();
			} else if (s[i] == '^'){
				push('^');
			} else if(s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*'){
				while ( top >= 0 && precedence(stack[top]) >= precedence(s[i])){
					expression += pop();
				}
				push(s[i]);
			} else {
				expression += s[i];
			}
		}
		return expression;
	}	
};

int main(){
	convert c = convert();
	cout << endl << c.infixToPostfix() << endl;
}
