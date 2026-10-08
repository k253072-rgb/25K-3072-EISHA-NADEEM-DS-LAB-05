#include <iostream>
using namespace std;

#define MAX 8
class Stack{
public:
	int top;
	int s[MAX];
	
	Stack(){
		top = -1;
	}
	
	bool isFull(){
		return top >= MAX - 1;
	}
	
	bool isEmpty(){
	 	return top == -1;
	}
	
	bool push(int d){
		if(isFull()){
			cout << "stack is full" << endl;
			return false;
		}
		
		s[++top] = d;
		cout << d << " pushed into stack" << endl;
		return true;
	}
	
	int undo(){
		if(isEmpty()){
			cout << "stack is empty" << endl;
			return -1;
		}
		
		int value = s[top--];
        cout << value << " removed from stack" << endl;
        return value;
	}
	
	int peek(){
		if(isEmpty()){
			cout << "stack is empty" << endl;
			return -1;
		}
		cout << "current top: " << s[top] << endl;
		return s[top];
	}
	
	void display(){
		if(isEmpty()){
			cout << "stack is empty" << endl;
			return;
		}
		
		for(int i = top; i >= 0; i--){
			cout << s[i] << endl;
		}
	}
	
};

int main(){
	//12, 25, 17, 31, 44, 19
	Stack s;
	s.push(12);
	s.peek();
	
	s.push(25);
	s.peek();
	
	s.push(17);
	s.peek();
	
	s.push(31);
	s.peek();
	
	s.push(44);
	s.peek();
	
	s.push(19);
	s.peek();
	
	s.undo();
	s.peek();
	
	s.undo();
	s.peek();
	
	s.undo();
	s.peek();
	
	s.push(52);
	s.peek();
	
	s.undo();
	s.peek();
	
	s.undo();
	s.peek();
	
	s.display();
	return 0;
	
}