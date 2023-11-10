#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Structure to represent a queue node
struct QueueNode {
    int data;
    QueueNode* next;

    QueueNode(int val) {
        data = val;
        next = NULL;
    }
};

// Structure to represent a queue
struct Queue {
    QueueNode* front;
    QueueNode* rear;

    Queue() {
        front = NULL;
        rear = NULL;
    }

    // Function to enqueue an element to the rear of the queue
    void enqueue(int val) {
        QueueNode* newNode = new QueueNode(val);
        if (rear == NULL) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Function to dequeue an element from the front of the queue
    int dequeue() {
        if (front == NULL) {
            return -1;
        }
        int val = front->data;
        QueueNode* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
        return val;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == NULL);
    }

    // Function to reverse the queue using a stack
    void reverse() {
        stack<int> s;
        while (!isEmpty()) {
            s.push(dequeue());
        }
        while (!s.empty()) {
            enqueue(s.top());
            s.pop();
        }
    }

    // Function to print the elements of the queue
    void display() {
        QueueNode* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int i,n,x;
    cout<<"Enter number of elements:";
    cin>>n;
    for(i=0;i<n;i++)
    {
    	cin>>x;
    	q.enqueue(x);	
	}
    cout << "Original Queue: ";
    q.display();
    q.reverse();
    cout << "Reversed Queue: ";
    q.display();
    return 0;
}
