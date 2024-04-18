// priorty queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <list>
using namespace std;

class ElemOfQueue {
public:
    string element;
    int prioritynum;
    ElemOfQueue() {
        prioritynum=0; }
    ElemOfQueue( const string &el ,int pn):element(el),prioritynum(pn){}

};
class PriorityQueue {
private:
    ElemOfQueue* elements;
    int length;
    int size;
public:
    PriorityQueue(int le) : length(le), size(0) {// constr
        elements = new ElemOfQueue[length];
     }
    ~PriorityQueue() {
        delete[] elements;
    }

    void enqueue(const string& element, int prioritynum) {
        if (length == size) {
            cout << "Queue is full Cannot enqueue" << endl;
            return;
        }

        int index = size;
        while (index > 0 && elements[index - 1].prioritynum >= prioritynum) {
            elements[index] = elements[index - 1];
            index--;
        }

        elements[index] = ElemOfQueue(element, prioritynum);
        size++;
    }

    void dequeue() {
        if (size == 0) {
           cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        for (int i = 0; i < size - 1; i++) {
            elements[i] = elements[i + 1];
        }

        size--;
    }

    void printQueue() const {
        for (int i = 0; i < size; i++) {
            cout << elements[i].element << " (priority: " << elements[i].prioritynum << ")" <<endl;
        }
    }
};

int main() {
    PriorityQueue priorityQueue(5);

    // Enqueue elements with priorities
    priorityQueue.enqueue("task A", 3);
    priorityQueue.enqueue("task B", 1);
    priorityQueue.enqueue("task C", 2);

    // Print the queue
    priorityQueue.printQueue();

    return 0;
}