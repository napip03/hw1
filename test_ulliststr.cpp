#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    std::cout << "Hello World!" << std::endl;
    ULListStr test = ULListStr();
    std::cout << test.empty() << " :3 " << std::endl;
    std::cout << test.size() << std::endl;
    //test.push_front("john"); std::cout << "--" << std::endl; 
    test.push_back("jimmy");
    //std::cout << "AFTER JIMMY" << std::endl;
    //std::cout << test.front() << " " << test.back() << std::endl;
    test.push_back("john");
    //std::cout << "finished push : " << test.back() << std::endl;
    test.pop_front();
    test.pop_front();
    //test.push_back(NULL); //null case testing
    std::cout << test.front() << " " << test.size() << std::endl;
    test.pop_back();
    //std::cout << "testing get with no items" << test.get(0) << "@";
    /* 
    test.push_back("tom"); test.push_front("tim"); test.push_front("timmy"); test.push_front("timmytam"); test.push_front("tedward");
    */
    //test.push_back("a");test.push_back("b");test.push_back("c");test.push_back("d");test.push_front("e");test.push_front("f");
    test.push_front("f"); 
    test.push_front("e");
    test.push_front("d"); 
    test.push_front("c");
    test.push_front("b");
    test.push_front("a");
    std::cout << "size is " << test.size() << ". front is " << test.front();
    test.pop_back();
    std::cout <<". tail is " << test.back()<< std::endl; 
    std::cout << "result from get() is ["<< test.get(4) << "]" << test.back() << std::endl;
    
}
