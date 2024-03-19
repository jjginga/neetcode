//
// Created by Joel Jose Ginga on 19/03/2024.
//

/**
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:
        MinStack() initializes the stack object.
        void push(int val) pushes the element val onto the stack.
        void pop() removes the element on the top of the stack.
        int top() gets the top element of the stack.
        int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.



Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
        MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2


Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.*/

class MinStack {
private:
    int* arr;
    int count, size, minVal;
public:

    //initialize the stack
    MinStack() {
        size = 10;
        count = 0;
        minVal = INT_MAX;
        arr = new int[size];
    }

    void push(int val) {

        //if the size is not enough we double the array
        if(count>=size){
            size = 2*size;
            int* newArr = new int[size];
            for(int i = 0 ; i < count ; i++){
                newArr[i]=arr[i];
            }
            delete[] arr;
            arr=newArr;
        }

        //check the min Value;
        minVal = min(minVal, val);

        arr[count++]=val;

    }

    void pop() {
        if (count == 0) return;

        //if pop is the minimum then we need to find another one
        if(arr[count-1]==minVal){
            minVal = INT_MAX;
            for(int i = 0 ; i < count-1 ; i++)
                minVal = min(minVal,arr[i]);
        }

        --count;
    }

    int top() {
        if (count == 0) return 0;
        return arr[count-1];
    }

    int getMin() {
        return minVal;
    }
};
