/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/
#include<iostream>
#include "split.h"

int main(int argc, char* argv[])
{
    Node* head = new Node(3, nullptr);
    Node* two  = new Node(2, nullptr);
    Node* five = new Node(5, nullptr);
    two->next = five;
    head->next = two;
    Node* curr = head;
    Node* odds = 0;
    Node* evens = 0;
    std::cout << head->value << std::endl;
    split(head, odds, evens);
    printNodes(head);
    printNodes(odds);
    printNodes(evens);
}
