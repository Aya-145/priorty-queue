// merge linked list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
//#include <list>
using namespace std;

struct Node {
    int val;
    Node* next;
};

//  insert at beginning of  circular ll
void insert(Node** head, int val) {
    Node* newNode = new Node;
    newNode->val = val;
    if (*head == nullptr) {
        newNode->next = newNode;
        *head = newNode;
    }
    else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
}

//  merge two circular linked lists && remove duplicates
Node* MergeCircularLists(Node* head1, Node* head2) {
    if (head1 == nullptr) {
        return head2;
    }
    if (head2 == nullptr) {
        return head1;
    }

    Node* result = nullptr;
    Node* temp1 = head1;
    Node* temp2 = head2;

    while (temp1->next != head1 && temp2->next != head2) {
        if (temp1->val < temp2->val) {
            insert(&result, temp1->val);
            temp1 = temp1->next;
        }
        else if (temp1->val > temp2->val) {
            insert(&result, temp2->val);
            temp2 = temp2->next;
        }
        else {
            insert(&result, temp1->val);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    //  remaining of list1
    while (temp1->next != head1) {
        if (temp1->val < temp2->val) {
            insert(&result, temp1->val);
        }
        else if (temp1->val > temp2->val) {
            insert(&result, temp2->val);
            temp2 = temp2->next;
        }
        else {
            insert(&result, temp1->val);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    //  remaining  of list2
    while (temp2->next != head2) {
        if (temp2->val < temp1->val) {
            insert(&result, temp2->val);
        }
        else if (temp2->val > temp1->val) {
            insert(&result, temp1->val);
            temp1 = temp1->next;
        }
        else {
            insert(&result, temp1->val);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        temp2 = temp2->next;
    }

    // last  of list1 and list2
    if (temp1->val < temp2->val) {
        insert(&result, temp1->val);
        insert(&result, temp2->val);
    }
    else if (temp1->val > temp2->val) {
        insert(&result, temp2->val);
        insert(&result, temp1->val);
    }
    else {
        insert(&result, temp1-> val);
    }

    return result;
}

//  display elements 
void display(Node* head) {
    if (head == nullptr) {
        return;
    }

    Node* temp = head;
    do {
        cout << temp->val << " ";
        temp = temp->next;
    } while (temp != head);

   cout << endl;
}

int main() {
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    insert(&head1, 5);// list1//this functiion insert at begin  
    insert(&head1, 4);// 4  5
    insert(&head1, 3);//3 4 5 
    insert(&head1, 2);//2  3  4  5
    insert(&head1, 1);//1  2  3  4  5 

   
    insert(&head2, 20);///list2// 20
    insert(&head2, 10);//  10   20 
    insert(&head2, 1);///1   10  20

    // after merging
    Node* mergedList;
        mergedList = MergeCircularLists(head1, head2);
    display(mergedList);

    return 0;
}
