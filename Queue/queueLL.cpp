#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

class QueueUsingLinkedList{
    public:
    Node* head; // acts like a front
    Node* tail;
    int size;

    QueueUsingLinkedList(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    // enqueue
    void enqueue(int element){
        Node* newNode = new Node(element);
        if(tail == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail -> next = newNode;
            tail = newNode;
        }
        size++;
    }

    int dequeue(){
        //check if queue is empty
        if(head == NULL){
            cout << "Queue is empty" << endl;
            return -1;
        }

        int val = head -> data;
        Node* temp = head;
        head = head -> next;

        // if queue becomes empty
        if(head == NULL){
            tail = NULL;
        }
        delete temp;
        size--;
        return val;
    }
    int getSize(){
        return size;
    }
    int front(){
        if(head == NULL){
            cout << "Queue is empty" << endl;
            return -1;
        }
        return head -> data;
    }

    bool isEmpty(){
        return head == NULL;
    }
};

int main(){
    QueueUsingLinkedList q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout << "size: " << q.getSize() << endl;

    while(!q.isEmpty()){
        cout << q.front() << endl;
        cout << "popped: " << q.dequeue() << endl;
    }
    cout << "size: " << q.getSize() << endl;
    cout << "Front: " << q.front() << endl;
}