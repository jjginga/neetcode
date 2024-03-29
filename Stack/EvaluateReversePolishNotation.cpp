//
// Created by Joel Jose Ginga on 20/03/2024.
//
Evaluate Reverse Polish Notation

/**
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.


Example 1:
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:
Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3:
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

*/

class EvaluateReversePolishNotation {
public:
    int evalRPN(vector<string>& tokens) {
        //we create a helper stack to store the numbers
        stack<int> stack;

        for(const string& token : tokens){
            //we check if it's an operator
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                //we pop the top two numbers from the stack;
                int num2 = stack.top(); stack.pop();
                int num1 = stack.top(); stack.pop();

                //we perform the operation
                if(token=="+") stack.push(num1+num2);
                if(token=="-") stack.push(num1-num2);
                if(token=="*") stack.push(num1*num2);
                if(token=="/") stack.push(num1/num2);
                continue;
            }

            //if the token is a number we store it on the stack
            stack.push(stoi(token));
        }

        return stack.top();
    }
};
