//
//  stack.cpp
//  q3
//
//  Created by toka magdy ragab  on 4/21/18.
//  Copyright © 2018 toka magdy ragab . All rights reserved.
//

#include "stack.hpp"
#include <iostream>
#include <string.h>

using namespace std;

stack::stack()
{
    top = -1;
}

void stack::push(char el)
{
    stackArray.addToDLLTail(el);
    top++;
}

char stack::pop()
{
    if (isEmpty())
        throw "Empty Stack";
    top--;
    char el = stackArray.getTail();
    stackArray.deleteFromDLLTail();
    return el;
}

bool stack::isEmpty()
{
    return top == -1;
}

char stack::Top()
{
    return stackArray.getTail();
}
