#include <iostream>
using namespace std;

class QueueUsingArray{
    public:
    int *data;
    int nextIndex;
    int size;
    int capacity;
    int first;

    // constructor
    public:
    QueueUsingArray(int capacity){
        this -> capacity = capacity;
        nextIndex = 0;
        size = 0;
        first = -1;
        data = new int[capacity];
    }

    void enqueue(int element){
        if(size == capacity){
            cout << "Queue is Full" << endl;
            return;
        }
        data[nextIndex] = element;
        cout << "index of: " << element << " " << nextIndex << endl;
        nextIndex = (nextIndex + 1) % capacity;
        if(first == -1){
            first = 0;
        }
        size++;
    }

    bool isEmpty(){
        if(size == 0) return true;
        else return false;
    }
    //dequeue
    int dequeue(){
        if(isEmpty()){
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int val = data[first];
        first = (first + 1) % capacity;
        size--;

        if(size == 0){
            nextIndex = 0;
            first = -1;
        }
        return val;
    }

    int front(){
        if(isEmpty()){
            cout << "Queue is empty!" << endl;
            return 0;
        }
        return data[first]; // first == front
    }

    int getSize(){
        return size;
    }
};

int main(){
    QueueUsingArray q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    int removed_val = q.dequeue();
    cout << "removed: " << removed_val << endl;
    q.enqueue(60);

    while(!q.isEmpty()){
        cout << q.front() << " ";
        int val = q.dequeue();
        cout << "Removed val: " << val << endl;
    }
}