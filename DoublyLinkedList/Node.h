#include <iostream>
using namespace std;

// Forward Traversal
// Backward Traversal
// InsertNodeAtPos
// DeleteNodeAtPos
// InsertAtHead, DeleteAtHead, InsertAtBack, DeleteAtBack

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    // constructor
    Node(int data){
        this -> data = data;
        next = NULL;
        prev = NULL;
    }
};

void printDoubly(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data;
        if(temp -> next != NULL){
            cout << "->";
        }
        temp = temp -> next;
    }
}