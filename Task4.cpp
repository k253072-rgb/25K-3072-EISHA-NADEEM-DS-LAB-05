#include <iostream>
using namespace std;

#define MAX 6

class CQueue{
	
private:
	int rear;
	int front;
	int num;
	int q[MAX];
	
public:
	
	CQueue(){
		front = 0;
		rear = -1;
		num = 0;
	}
	
	bool isEmpty(){
		return num==0;
	}
	
	bool isFull(){
		return num == MAX;
	}
	
	void enqueue(int id){
		if(isFull()){
			cout << "Space is full. no more passengers can board"<<endl;
			return;
		}
		
		rear = (rear + 1) % MAX;
		q[rear] = id;
		num++;
	}
	
	int dequeue(){
		if(isEmpty()){
			cout << "no passengers"<<endl;
			return -1;
		}
		int id = q[front];
		front = (front + 1) % MAX;
		num--;
		
	    if(num == 0){
	        front = 0;
	        rear = -1;
	    }
    
		return id;
	}
	
	void display(){
		if(isEmpty()){
			cout << "no passengers"<<endl;
			return;
		}
		
		cout << "Passenger IDs: " << endl;
		
		int index = front;
		
		for(int i = 0; i < num; i++){
			cout << q[index] << endl;
			index = (index + 1) % MAX;
		}
		cout << endl;
		
		cout << "Final front position: " << front << endl;
    	cout << "Final rear position: " << rear << endl;
	}
	
};

int main(){
	CQueue q;
	q.enqueue(101);
	q.enqueue(102);
	q.enqueue(103);
	q.enqueue(104);
	q.enqueue(105);
	q.enqueue(106);
	
	q.dequeue();
	q.dequeue();
	q.dequeue();
	
	q.enqueue(107);
	q.enqueue(108);
	q.enqueue(109);
	
	q.dequeue();
	q.dequeue();
	
	q.enqueue(110);
	
	q.dequeue();
	
	q.enqueue(111);
	q.enqueue(112);
	
	q.display();
	
	return 0;
}