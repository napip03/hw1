/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/
#include<iostream>
#include "split.h"

int main(int argc, char* argv[]) //only failing atm InputSet_to_Null
{
    Node* head = new Node(3, nullptr); 
    Node* two  = new Node(2, nullptr);
    Node* zero = new Node(0, nullptr);
    Node* four = new Node(4, nullptr);
    two->next = zero;
    head->next = two;
    zero->next = four;
    Node* odds = nullptr;
    Node* evens = nullptr;
    //std::cout << head->value << std::endl;
    split(head, odds, evens);
    std::cout << (head == nullptr) << std::endl;
    printNodes(head);
    printNodes(odds);
    printNodes(evens);
    //delete [] head; delete [] two; delete [] five;
}
