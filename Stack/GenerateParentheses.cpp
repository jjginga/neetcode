//
// Created by Joel Jose Ginga on 22/03/2024.
//
/**
* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*
*Example 1:
*Input: n = 3
*Output: ["((()))","(()())","(())()","()(())","()()()"]
*
*Example 2:
*Input: n = 1
*Output: ["()"]
*
*Constraints:
*1 <= n <= 8
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        helper("", n, n, vec);
        return vec;
    }

    // Helper function that uses recursion to generate all combinations.
    void helper(string current, int open, int close, vector<string>& vec){
        // Base case: when there are no more open or close parentheses to add,
        // meaning a valid combination has been formed.
        if(open==0 && close == 0){
            vec.push_back(current);
            return;
        }

        // Recursive case 1: If there are open parentheses left to add,
        // add an open parenthesis and recursively call the helper function,
        // decreasing the count of open parentheses.
        if(open>0)
            helper(current+"(", open-1, close, vec);
        // Recursive case 2: If there are more close parentheses left than open ones,
        // it means we can add a close parenthesis (to keep the sequence well-formed).
        // Recursively call the helper function, decreasing the count of close parentheses.
        if(close>open)
            helper(current+")", open, close-1, vec);
    }
};