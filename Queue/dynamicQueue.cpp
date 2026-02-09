#include <iostream>
using namespace std;

class DynamicQueue{
    int *data;
    int capacity;
    int nextIndex;
    int first;
    int size;

    // constructor 
    public:
    DynamicQueue(int capacity){
        this -> capacity = capacity;
        data = new int[capacity];
        size = 0;
        nextIndex = 0;
        first = -1;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    void enqueue(int element){
        //check if queue is full
        if(size == capacity){
            int* newData = new int[2 * capacity];
            int j = 0;
            for(int i = 0; i < size; ++i){
                newData[j] = data[(first + i) % capacity];
                j++;
            }
            delete [] data;
            data = newData;
            first = 0;
            nextIndex = size;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if(first == -1){
            first = 0;
        }
        size++;
    }

    int dequeue(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
        }
        int ans = data[first];
        first = (first + 1) % capacity;
        size--;

        if(size == 0){
            first = -1;
            nextIndex = 0;
        }
        return ans;
    }

    int front(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
        }
        return data[first];
    }
};