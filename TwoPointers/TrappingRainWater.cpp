//
// Created by Joel Jose Ginga on 12/03/2024.
//
/**
    * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

      Example 1:
      Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
      Output: 6
      Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

      Example 2:
      Input: height = [4,2,0,3,2,5]
      Output: 9
 *
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();

        //create vectors so store the maximum height to the left and to the right
        vector<int> maxLeft(size), maxRight(size);
        int water = 0;

        //there is nothing to the left
        maxLeft[0] = height[0];

        for(int i = 1 ; i < size ; i++){
            maxLeft[i] = max(maxLeft[i-1], height[i]);
        }

        //there is nothing to the right
        maxRight[size-1] = height[size-1];
        for(int i = size-2 ; i >= 0 ; i--){
            maxRight[i] = max(maxRight[i+1], height[i]);

            //the water trapped is determine by the shorter of the two sides  subtracting the current height
            water += min(maxLeft[i],maxRight[i]) - height[i];
        }

        return water;
    }
};