#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Stack{
	public:
	int top;
	string s[MAX];
	
	Stack(){
		top = -1;
	}
	
	bool isFull(){
		return top >= MAX - 1;
	}
	
	bool isEmpty(){
	 	return top == -1;
	}
	
	bool push(string d){
		if(isFull()){
			return false;
		}
		
		s[++top] = d;
		return true;
	}
	
	string pop(){
		if(isEmpty()){
			return "";
		}
		string d = s[top];
		top--;
		return d;
	}
	
	void clear(){
		top = -1;
	}
	
	void display(){
		if(isEmpty()){
			cout << "stack is empty" << endl;
			return;
		}
		
		for(int i = 0; i <= top; i++){
			cout << s[i] << (i == top ? "" : " ");
		}
		cout << endl;
	}
	
};
class Document{
public:
	Stack undoStack;
	Stack redoStack;
	
	void type(string word){
		undoStack.push(word);
		redoStack.clear();
	}
	
	void undo(){
		 if(undoStack.isEmpty()){
            cout << "Nothing to undo" << endl;
            return;
        }
		string undo = undoStack.pop();
		redoStack.push(undo);
	}
	
	void redo(){
		 if(redoStack.isEmpty()){
            cout << "Nothing to redo" << endl;
            return;
        }
		string redo = redoStack.pop();
		undoStack.push(redo);
	}
	
	void display(){
		cout << "Document: ";
		undoStack.display();
	}
	
};

int main(){
	Document d;
    d.type("Hello");
    d.display();

    d.type("World");
    d.display();

    d.undo();
    d.display();

    d.redo();
    d.display();

    d.undo();
    d.display();

    d.type("There");
    d.display();

    d.redo();
    d.display();
    
    return 0;
}