//
//  main.cpp
//  q3
//
//  Created by toka magdy ragab  on 4/21/18.
//  Copyright © 2018 toka magdy ragab . All rights reserved.
//

#include <iostream>
#include <string.h>
#include "stack.hpp"

using namespace std;

void checkBalance(string code)
{
    int i = 0, lineNum = 1;
    stack s;
    bool temp = false;
    while (code[i] != '\0')
    {
        if (code[i] == '@' && code[i+1] == '@')
        {
            lineNum++;
            i++;
        }
        if (code[i] == '(' || code[i] == '[' || code[i] == '{')
            s.push(code[i]);
        else if (code[i] == '/' && code[i+1] == '*')
        {
            s.push(code[i]);
            i++;
        }
        else if (code[i] == ')')
        {
            if (s.isEmpty() || s.pop() != '(')
            {
                cout << "There are unbalanced bracket:\"()\" in line#" << lineNum << endl ;
                temp = true;
            }
        }
        else if (code[i] == ']')
        {
            if (s.isEmpty() || s.pop() != '[')
            {
                cout << "There are unbalanced bracket:\"[]\" in line#" << lineNum << endl;
                temp = true;
            }
        }
        else if (code[i] == '}')
        {
            if (s.isEmpty() || s.pop() != '{')
            {
                cout << "There are unbalanced bracket:\"{}\" in line#" << lineNum << endl;
                temp = true;
            }
        }
        else if (code[i] == '*' && code[i+1] == '/')
        {
            if (s.isEmpty() || s.pop() != '/')
            {
                cout << "There are unbalanced bracket:\"/**/\" in line#" << lineNum << endl;
                temp = true;
            }
        }
        i++;
    }

    if (!s.isEmpty())
    {
        temp = true;
        cout << "There are extra open brackets:";
        do
        {
            cout << s.pop() << "  ";
        }
        while (!s.isEmpty());
        cout << endl;
    }
    
    if (!temp)
        cout << "The code is balanced" << endl;
}

int main(int argc, const char * argv[]) {
    string code = "", line;
    cout << "Enter the code you want to check the balance of with the word \"done\" in the end";
    getline(cin,line);
    while (strcasecmp(line.c_str(),"done") != 0)
    {
        code += line + "@@";
        getline(cin,line);
    }
    checkBalance(code);
    return 0;
}
