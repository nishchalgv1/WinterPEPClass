#include <iostream>
#include "Node.h"
using namespace std;

int main(){
    // create nodes dynamically

    Node* head = new Node(10);
    Node* secondNode = new Node(200);
    Node* thirdNode = new Node(300);

    head -> next = secondNode;
    secondNode -> next = thirdNode;
    thirdNode -> next = nullptr;

    printLinkedList(head);
    
}