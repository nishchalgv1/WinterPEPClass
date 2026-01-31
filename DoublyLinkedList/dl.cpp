#include <iostream>
#include "Node.h"
using namespace std;

//takeInput
Node* takeInput(){
    int data;
    cout << "Enter new data: " << endl;
    cin >> data;

    Node* head = NULL;
    Node* tail = NULL;
    while(data != -1){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
        cout << "Enter data again: " << endl;
        cin >> data;
    }
    return head;
}

void printBackwardList(Node* head){
    Node* temp = head;
    //now calculate the tail from head
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    Node* tail = temp; // tailNode

    // print the list from tail
    while(tail != NULL){
        cout << tail -> data;
        if(tail -> prev != NULL){
            cout << "->";
        }
        tail = tail -> prev;
    }
}

int main(){
    Node* head = takeInput();
    printBackwardList(head);
}