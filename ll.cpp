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

int main(){
    // first create nodes statically
    Node n1(10);
    Node n2(20);
    Node n3(30);
    Node n4(40);
    Node n5(50);

    Node* head = &n1;
    n1.next = &n2; // n1 points to n2
    n2.next = &n3; // n2 points to n3
    n3.next = &n4; // n3 points to n4
    n4.next = &n5; // n4 points to n5
    n5.next = nullptr;

    cout << "head data: " << head -> data << endl;
    cout << "n2 -> data: " << n2.data << endl;
    cout << "n3 data through n2: " << n2.next -> data << endl;

    // print function to print the linked list
    printLinkedList(head);

    // 10 -> 20 -> 30 -> 40 -> 50 -> null

}