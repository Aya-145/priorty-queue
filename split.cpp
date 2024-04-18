// split.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


//************************************************************
////  ***time comlexity o(n)***            **space o(1)**
//***********************************************************
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};
void splitList(Node* head, Node** head1_ref, Node** head2_ref) {
    Node* first = head;
    Node* last = head;

    if (head == nullptr)
        return;

   
    while (last->next != nullptr && last->next->next != nullptr) {
        last = last->next->next;
        first = first->next;
    }
   
    
   // if even 
    /*if (last->next->next ==head )
        last = last->next;
    *head1_ref = head;*/
   

    if (head->next != head)
    *head2_ref = first->next;
    last->next = first->next;
    first->next = head;
}

// insert  at begin
void insert(Node** head_ref, int data) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = *head_ref;
    new_node->prev = nullptr;

    if (*head_ref != nullptr) {
        (*head_ref)->prev = new_node;
    }
    *head_ref = new_node;
}

// print 
void printList(Node* head) {
    Node* temp = head;
   
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;

    }
}

int main() {
    Node* head = nullptr;
    Node* head1 = nullptr;
    Node* head2 = nullptr;
// Create 1->2->3->
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);
    cout << "Original Doubly Linked List is : ";
    printList(head);

    //  after Split 
    splitList(head, &head1, &head2);

  cout << "\nFirst Half: ";
    printList(head1);
 cout << "\nSecond Half: ";
    printList(head2);

    return 0;
}