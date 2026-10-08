#include <iostream>
#include <stack>
using namespace std;

#define MAX 100
class Queue{
public:
	int front;
	int rear;
	int q[MAX];
	
	Queue(){
		front = -1;
		rear = -1;
	}
	
	bool isFull() {
    return rear == MAX - 1;
}

	bool isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }
    if (front == -1) {
        front = 0; 
    }
    rear++;
    q[rear] = value;
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1;
    }
    int item = q[front];
    front++;
    
    // reset pointers when queue becomes empty after dequeue
    if (front > rear) {
        front = -1;
        rear = -1;
    }
    
    return item;
}

int peek() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q[front];
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}
};

void reverseFirstK(Queue &q, int k){
	
	if(q.isEmpty() || k <= 0)
	return;
	
     int size = (q.rear - q.front) + 1;

    if(k > size)
    return;

	stack<int> s;
	
	for(int i = 0; i < k; i++){
		s.push(q.dequeue());
	}
	
	while(!s.empty()){
		q.enqueue(s.top());
		s.pop();
	}
	
	for(int i = 0; i < size - k; i++){
		q.enqueue(q.dequeue());
	}
	
}

int main(){
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.enqueue(7);
	
	int k = 3;
	
	reverseFirstK(q, k);
	
	q.display();
	
	return 0;
	
}