//
// Created by Joel Jose Ginga on 31/03/2024.
//
/**
 *Given an array of integers heights representing the histogram's
 *bar height where the width of each bar is 1, return the area of
 *the largest rectangle in the histogram.
 *
 *Example 1:
 *Input: heights = [2,1,5,6,2,3]
 *Output: 10
 *Explanation: The above is a histogram where width of each bar is 1.
 *The largest rectangle is shown in the red area, which has an area = 10 units.
 *
 *Example 2:
 *Input: heights = [2,4]
 *Output: 4
*/

class LargestRectangleInHistogram{
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int> stack;
        int n = heights.size();

        //iterate through each bar in the histogram plus one additional iteration
        //for the last value to ensure we can calculate area for all bars
        for(int i = 0 ; i <= n; i++){
            //we use 0 has the last value for the height to handle remaining bars in stack after processing
            //all the bars in histogram
            int h = (i == n) ? 0 : heights[i];

            //calculate the areas of the bars to the right taller than the current bar
            while(!stack.empty() && heights[stack.top()]>h){
                int height = heights[stack.top()]; stack.pop();
                int width = stack.empty() ? i : i - stack.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            stack.push(i);
        }
        return maxArea;
    }
};