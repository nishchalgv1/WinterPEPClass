#include <iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next; // pointer to the next node

    //constructor
    Node(int data){
        this -> data = data;
        next = NULL;
    }
};

void printLinkedList(Node* head){
        Node* temp = head;
    while(temp != NULL){
        cout << temp -> data;
        if(temp -> next != NULL){
            cout << "->";
        }
        temp = temp -> next;
    }
}

Node* takeInputBetter(){
    int data;
    cout << "Enter data: " << endl;
    cin >> data;
    // head and tail
    Node* head = NULL;
    Node* tail = NULL;
    while(data != -1){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail -> next = newNode;
            tail = newNode;
        }
        cout << "Enter data again: " << endl;
        cin >> data;
    }
    return head;
}

int main(){
    Node* head = takeInputBetter();
    printLinkedList(head);
}