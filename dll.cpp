//
//  dll.cpp
//  q3
//
//  Created by toka magdy ragab  on 4/21/18.
//  Copyright © 2018 toka magdy ragab . All rights reserved.
//

#include "dll.hpp"

DoublyLinkedList::DoublyLinkedList()
{
    head = tail = 0;
}

void DoublyLinkedList::addToDLLTail(const char& x)
{
    if (isEmpty())
        addToDLLHead(x);
    else
    {
        tail->next = new DLLNode(x,0,tail);
        tail = tail->next;
    }
}

char DoublyLinkedList::deleteFromDLLTail()
{
    if (isEmpty())
        throw "list is empty";
    char x = tail->info;
    if (head == tail)
        deleteFromDLLHead();
    else
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = 0;
    }
    return x;
}

DoublyLinkedList::~DoublyLinkedList()
{
    clear();
}

bool DoublyLinkedList::isEmpty() const {
    return head == 0;
}

void DoublyLinkedList::clear()
{
    while (!isEmpty())
        deleteFromDLLHead();
}

void DoublyLinkedList::setToNull() {
    head = tail = 0;
}

void DoublyLinkedList::addToDLLHead(const char& x)
{
    if (isEmpty())
    {
        head = new DLLNode(x);
        tail = head;
    }
    else
    {
        DLLNode *temp = new DLLNode(x,head);
        head->prev = temp;
        head = temp;
    }
}

char DoublyLinkedList::deleteFromDLLHead()
{
    if (isEmpty())
        throw "list is empty";
    char x = head->info;
    if (head == tail)
    {
        delete head;
        head = tail = 0;
    }
    else
    {
        head = head->next;
        delete head->prev;
        head->prev = 0;
    }
    return x;
}

char& DoublyLinkedList::firstEl()
{
    if (isEmpty())
        throw "empty list";
    return head->info;
}

char* DoublyLinkedList::find(const char& x) const
{
    DLLNode *temp;
    for (temp = head; temp->info != x && temp != 0; temp = temp->next);
    if (temp == 0)
        return 0;
    else
        return &temp->info;
}

char DoublyLinkedList::getTail()
{
    if (isEmpty())
        throw "Empty";
    return tail->info;
}
