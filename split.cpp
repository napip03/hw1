/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
/* Add a prototype for a helper function here if you need */
//#include<iostream>
void split(Node*& in, Node*& odds, Node*& evens)
{
  //std::cout << in->value << std::endl;
  /* Add code here */
  //if p is empty or has no content/doesnt exist. recursion has ended. break/return none;
  if (!in || in == nullptr) //idk why in==nullptr doesnt work. it said "split.cpp:20:13: error: use of 
  //undeclared identifier 'null' if (in == nullptr)"
  {
    //std::cout << "ENTERS NULL CASE for in/in.value || " << (int)NULL << std::endl;
    return;
  }
  //if head is odd; add head to odds; recall function change location of odds to odds->next and in to in->next;
  if (in->value % 2 == 1) //odd
  {
    //add in to odds
    if (!odds)
    {
      odds = new Node(in->value, nullptr);
    }
    else
    {
        //std::cout << "ENTERS HERE EVER -else odd-" << std::endl;
        odds->next = in;
    }
    //warning this will cause the next "value" of the list to be the next of "in"
    split(in->next, odds->next, evens);
  }
  //if head is even; add head to evens; recall function change location of evens to evens->next and in to in->next;
  else if (in->value % 2 == 0 || in->value == 0) //even
  {
    //add in to evens
    if (!evens)
    {
      evens = new Node(in->value, nullptr);
    }
    else{
      //std::cout << "ENTERS HERE EVER -else even-" <<std::endl;
      evens->next = in;
    }
    split(in->next, odds, evens->next);
  }
  //cleaning
  //evens = evens->next;
  //odds = odds->next;
  in = nullptr;
}

/* If you needed a helper function, write it here */
/*
*/