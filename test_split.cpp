#include "split.h"
#include <iostream>

 
Node* newNode(int value) {
    return new Node(value, nullptr); / 
}

 
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->value << " ";  
        head = head->next;
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
     
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

     
    Node* odds = nullptr;
    Node* evens = nullptr;
    split(head, odds, evens);

     
    std::cout << "Odd List: ";
    printList(odds);

    std::cout << "Even List: ";
    printList(evens);

     
    Node* temp;
    while (odds != nullptr) {
        temp = odds;
        odds = odds->next;
        delete temp;
    }

    while (evens != nullptr) {
        temp = evens;
        evens = evens->next;
        delete temp;
    }

    return 0;
}
