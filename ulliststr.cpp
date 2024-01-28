#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream> //added IOSTREAM to print for testing
ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
//each node has a defined ARRSIZE of 10
// push_back, push_front, pop_back, pop_front, back, front and getValAtLoc 
void ULListStr::pop_front()
{
  //std::cout << "enter front : first loc at " << head_->first << " : " << std::endl;
  if ( size_ == 0 || head_->first  == head_->last) //if 0 items in val[] then nothing can be popped
    return;
  else{ 
        //std::cout << "bad accesss at val[" << head_->first << "] : "<< head_->val[0]  << std::endl;
        head_->val[head_->first] = std::string();  //val at first index of head is popped
        head_->first+=1; //and then the first index is updated
        size_--;  
        
  }
}
void ULListStr::pop_back()
{
  if (size_ == 0 || tail_->first  == tail_->last) //same functionality as pop front but with back
    return;
  tail_->val[tail_->last] = std::string();
  tail_->last-=1;
  size_--; 
}
void ULListStr::push_front(const std::string& val)
{
  if (val == std::string()) //NULL inpput protection 
    return;
  if (!head_) // head doesn't exist
  {
    head_ = new Item(); //create node 
    tail_ = head_; //head is tail with only 1 node
    head_->val[0] = val; 
    head_->last++;
    size_++;
  }
  else if (head_->first == 0)// head is full at the front 
  {
    Item* curr = new Item();// create new item if prev_array full and reassign head
    curr->val[0] = val; //give first index val
    curr->last = 1; // update last
    curr->next = head_;
    head_->prev = curr;
    head_= curr; //update head
    size_++; //update size
  }

  else
  {
    head_->val[head_->first-1] = val; //assign the new value to the front. move the front back.
    head_->first-=1;
    size_++;
  }
}
void ULListStr::push_back(const std::string& val) //maybe think about the null case
{
  if (!head_ && !tail_)//case 1: empty LLIST ; if head doesn't exist. create it and add "val"
  {
    //std::cout << "case1 "<<std::endl;
    head_ = new Item();
    head_->val[0] = val;
    head_->last++;
    tail_ = head_;
    size_++;
  }
  else if (head_->last == ARRSIZE && head_->next == nullptr ) //if head is full and tail doesn't exist. 
  {
    //std::cout << "case2 "<<std::endl;
    tail_ = new Item();//create new item, assign tail to it.
    tail_->val[0] = val;
    tail_->prev = head_;
    head_->next = tail_;
    tail_->last++;
    size_++;
  }

  else if (tail_->last == ARRSIZE) //if tail exist, but is full. create new item (that is now the new tail)
  {
    //std::cout << "case3" << std::endl;
    Item* curr = new Item();// create new item if prev item (tail) is full and reassign tail
    curr->val[0] = val;
    curr->last = 1;
    curr->prev = tail_; //update tail and connect the nodes
    tail_->next = curr;
    tail_= curr;
    size_++;
  }
  else //tail exist and is not full
  {
    //std::cout << "case3" << std::endl;
    tail_->val[tail_->last++] = val;
    size_++;
  }
}
std::string const & ULListStr::front() const //think about Null_case
{
  if (head_)
  {
    return head_->val[head_->first]; 
  }
  return std::string();//NULL
}
std::string const & ULListStr::back() const
{
  if (head_ || tail_)
  {
    return tail_->val[tail_->last-1];
  }
  std::cout << "returns null from back()" << std::endl;
  return std::string();
}
//O(N)
std::string* ULListStr::getValAtLoc(size_t loc) const //clarrify if loc includes empty unassigned val[]
{
  if (loc > size_)
    return nullptr;
  Item* curr = head_;
  int i = 0;
  std::cout << "****"<<curr->last - curr->first << "****^"<< loc <<"^"<< std::endl;
  while (loc > (curr->last - curr->first - 1))
  {
    std::cout << i;
    loc-= (curr->last - curr->first);
    std::cout << "within getVal @ node "<<  i  << " loc is " << loc << std::endl;
    //subtract from location
    curr = curr->next;
    i++;
    std::cout << "$$$" << loc << "$$$";
  }
  if (loc < 0 )
    {
      std::cout<<"LOC compututation error"<<std::endl;
      return nullptr; 
    }
    std::cout << "$$$" << loc << "$$$"; // << curr->first << curr->last << std::endl;
  //std::cout << "index after while loop is " << loc << ". IS CURRENT NODE HEAD/TAIL" << (curr == head_ || curr == tail_) << std::endl; 
  return &curr->val[loc+ curr->first];
  //return curr->&value[loc - curr->first];
}
/*
   * Overwrites the old value at index, pos, with val
   *   - Can run in O(n)
*/
void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
