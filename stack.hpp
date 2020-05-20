//
//  stack.hpp
//  q3
//
//  Created by toka magdy ragab  on 4/21/18.
//  Copyright © 2018 toka magdy ragab . All rights reserved.
//

#ifndef stack_hpp
#define stack_hpp

#include <stdio.h>
#include "dll.hpp"

using namespace std;

class stack
{
    DoublyLinkedList stackArray;
    int top;
public:
    stack();
    void push(char);
    char pop();
    char Top();
    bool isEmpty();
};


#endif /* stack_hpp */
