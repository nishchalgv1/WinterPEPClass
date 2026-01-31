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

Node* takeInput2(){
    int data;
    cout << "Enter data: " << endl;
    cin >> data;
    Node* head = NULL;
    while(data != -1){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
        }else{
            Node* temp = head;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
        cout << "Enter data again: " << endl;
        cin >> data;
    }
    return head;
}

Node* insertAtHead(Node* head, int data){
    // create the new node
    Node* newNode = new Node(data);
    Node* temp = head;
    newNode -> next = temp;
    head = newNode;
    return head;
}

Node *insertAtPos(Node* head, int pos, int data){
    if(pos == 0){
        //create new Node
        Node* newNode = new Node(data);
        newNode -> next = head;
        head = newNode;
        return head;
    }
    Node* temp = head; 
    int counter = 0;
    while(temp -> next != NULL && counter < pos - 1){
        temp = temp -> next;
        counter++;
    }

    if(temp == NULL){
        return head;
    }

    Node* newNode = new Node(data);
    newNode -> next = temp -> next;
    temp -> next = newNode;
    
    return head;
}


int main(){
    Node* head = takeInput2();
    int data;
    cout << "Enter the newNode data: " << endl;
    cin >> data;
    int pos;
    cout << "Enter position: " << endl;
    cin >> pos;
    Node* newHead = insertAtPos(head, pos, data);
    printLinkedList(newHead);
}