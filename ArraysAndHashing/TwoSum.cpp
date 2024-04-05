//
// Created by Joel Jose Ginga on 15/02/2024.
//

/**
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 *
 * Example 1:
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 *
 * Example 2:
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 *
 * Example 3:
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 *  *
*/
#include <unordered_map>

class TwoSum {
public:
    //this function has the complexity O(n) since we only go through the array once
    vector<int> twoSum(vector<int>& nums, int target) {
        //we create a map to map the value and it's index
        unordered_map<int, int> numMap;

        for(int i  = 0 ; i < nums.size() ; i++){
            //for each number we calculate the complement
            int complement = target - nums[i];
            //and check if we already found it in the vector
            if(numMap.find(complement) != numMap.end())
                return{numMap[complement], i};
            numMap[nums[i]]=i;
        }
        return {};
    }
};