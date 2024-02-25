//
// Created by Joel Jose Ginga on 15/02/2024.
//


/**
    Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

    Example 1:
    Input: nums = [1,2,3,1]
    Output: true

    Example 2:
    Input: nums = [1,2,3,4]
    Output: false

    Example 3:
    Input: nums = [1,1,1,3,3,4,3,2,4,2]
    Output: true
*/
#include <vector>
#include <unordered_set>

class ContainsDuplicate {
public:
    //the complexity is O(n)
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> set;
        for(int num : nums) {
            if(set.find(num) != set.end())
                return  true;
            set.insert(num);
        }
        return false;
    }
};