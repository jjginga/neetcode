//
// Created by Joel Jose Ginga on 18/03/2024.
//

/**
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false*/

class ValidParentheses {
public:
    bool isValid(string s) {
        stack<char> myStack;

        for(auto ch : s){
            if(ch == '(' || ch == '[' || ch == '{'){
                myStack.push(ch);
                continue;
            }
            if(myStack.empty())
                return false;
            auto open = myStack.top();
            myStack.pop();

            if( (ch == ')' && open == '(') ||
                (ch == ']' && open == '[') ||
                (ch == '}' && open == '{') )
                continue;
            return false;
        }

        return myStack.empty();
    }
};
