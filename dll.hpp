//
//  dll.hpp
//  q3
//
//  Created by toka magdy ragab  on 4/21/18.
//  Copyright © 2018 toka magdy ragab . All rights reserved.
//

#ifndef dll_hpp
#define dll_hpp

#include <stdio.h>
#include <iostream>

using namespace std;


class DLLNode {
public:
    DLLNode() {
        next = prev = 0;
    }
    DLLNode(const char& el, DLLNode *n = 0, DLLNode *p = 0) {
        info = el; next = n; prev = p;
    }
    char info;
    DLLNode *next, *prev;
};

class DoublyLinkedList

{
public:
    DoublyLinkedList();
    char getTail();
    void addToDLLTail(const char&);
    char deleteFromDLLTail();
    ~DoublyLinkedList();
    bool isEmpty() const;
    void clear();
    void setToNull();
    void addToDLLHead(const char&);
    char deleteFromDLLHead();
    char& firstEl();
    char* find(const char&) const;
    
protected:
    DLLNode *head, *tail;
    friend ostream& operator<<(ostream& out, const DoublyLinkedList& dll)
    {
        for (DLLNode *tmp = dll.head; tmp != 0; tmp = tmp->next)
            out << tmp->info << ' ';
        return out;
    }
};

#endif /* dll_hpp */
