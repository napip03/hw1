#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

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

}
void ULListStr::pop_back()
{

}
void ULListStr::push_front(const std::string& val)
{
  if (head_->last == ARRSIZE && head_->first == 0)
  {
    Item* curr = new Item();// create new item if prev_array full and reassign head
    curr->val[0] = val; //give first index val
    curr->last = 1; // update last
    head_->prev = curr; 
    head_= curr; //update head
    size_++;  //update size 
  }
  else
  {
    head_->val[head_->first--] = val;
    size_++;
  }
}
void ULListStr::push_back(const std::string& val)
{
  if (tail_->last == ARRSIZE)
  {
    Item* curr = new Item();// create new item if prev item (tail) is full and reassign head
    curr->val[0] = val; 
    curr->last = 1;
    curr->prev = tail_;
    tail_->next = curr;
    tail_= curr; 
    size_++;
  }
  else
  {
    tail_->val[tail_->last++] = val;
    size_++;
  }
}
std::string const & ULListStr::front() const //think about Null_case
{
  return head_->val[0];
}
std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last];
}
//O(N)
std::string* ULListStr::getValAtLoc(size_t loc) const //clarrify if loc includes empty unassigned val[]
{
  Item* curr = head_;
  if (loc >= size_)
  {
    return nullptr;
  }
  int i = 0;
  
  while(i < loc)
  {
    int size = head_->last - head_->first;
    i+= head_->first + head_->last;
    if (/*range > index */ true )
    {

    }
    //subtract from location
    curr = curr->next;
  }
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
