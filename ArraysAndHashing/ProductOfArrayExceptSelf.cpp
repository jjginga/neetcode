//
// Created by Joel Jose Ginga on 23/02/2024.
//

/**
 * Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

    You must write an algorithm that runs in O(n) time and without using the division operation.

    Example 1:
    Input: nums = [1,2,3,4]
    Output: [24,12,8,6]

    Example 2:
    Input: nums = [-1,1,0,-3,3]
    Output: [0,0,9,0,0]
 *
 */

class ProductOfArrayExceptSelf {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> result(nums.size(),1);
        std::vector<int> prefix(nums.size(),1);
        std::vector<int> suffix(nums.size(),1);
        int size = nums.size()-1;
        for(int i = 1 ; i < nums.size() ; i++) {
            prefix[i] *= prefix[i-1] * nums[i-1];
            suffix[size-i] = suffix[size-i+1] * nums[size-i+1];
        }

        for(int i = 0 ; i < nums.size() ; i++)
            result[i] = suffix[i] * prefix[i];
        return result;

    }
};