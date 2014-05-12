#include <iostream>
#include <string>
#include <stack>

using namespace std;
using std::stack;

bool isSpecial(const char & c)
{
    switch (c) {
        case '(':
        case ')':
        case '{':
        case '}':
        case '[':
        case ']':
            return true;
        default:
            return false;
    }   
}

char other(const char & c){
    switch (c) {
        case ')':
            return '(';
            break;
        case '}':
            return '{';
            break;
        case ']':
            return '[';
            break;
        default: 
            return '~';
            break;
    }    
}


bool isBalanced(const std::string & str)
{
    stack<char> stk;
    
    for (const char & c : str){
        if (isSpecial(c)){
            if (stk.size() && stk.top() == other(c)){
                stk.pop();
            } else {
                stk.push(c);
            }
        }
    }    
    return (stk.size() == 0);
}


int main()
{
    string test("{[()]}{}[]()");
    
    cout << test << " is balanced? : " << 
        isBalanced(test) << endl;
    
    return 0;
}

