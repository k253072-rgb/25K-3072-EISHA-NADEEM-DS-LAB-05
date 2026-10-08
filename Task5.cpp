#include <iostream>
using namespace std;

#define MAX 20

class Stack {
public:
    int top;      
    char arr[MAX]; 

    Stack() {
        top = -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(char value) {
        if (isFull()) {
            return;
        }
        top++;
        arr[top] = value;
    }

    char pop() {
        if (isEmpty()) {
            return -1;
        }
        char item = arr[top];
        top--;
        return item;
    }

    char peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }

        cout << "Stack elements (Top to Bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class MyQueue{
public:
	Stack incoming;
	Stack outgoing;
	
	void enqueue(char id){
		incoming.push(id);
	}
	
	char dequeue(){
    if(outgoing.isEmpty()){
        while(!incoming.isEmpty()){
            outgoing.push(incoming.pop());
        }
    }

    return outgoing.pop();
}
};

int main(){
	MyQueue q;
	
	q.enqueue('A');
	q.enqueue('B');
	cout << q.dequeue() << endl;
	q.enqueue('C');
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	
	return 0;
}