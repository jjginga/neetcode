//
// Created by Joel Jose Ginga on 30/05/2024.
//
/**
 *Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
 * There is only one repeated number in nums, return this repeated number.
 * You must solve the problem without modifying the array nums and uses only constant extra space.
 *
 * Example 1:
 * Input: nums = [1,3,4,2,2]
 * Output: 2
 *
 * Example 2:
 * Input: nums = [3,1,3,4,2]
 * Output: 3
 *
 * Example 3:
 * Input: nums = [3,3,3,3,3]
 * Output: 3
 *
 */

class FindTheDuplicateNumber {
public:
    int findDuplicate(vector<int>& nums) {

        int turtle = nums[0];
        int hare = nums[0];

        //first phase: Finding the intersection point within the cycle
        //this loop will continue until the turtle and hare meet
        while(true){
            turtle = nums[turtle];
            hare = nums[nums[hare]];
            if(turtle == hare)
                break;
        }

        turtle = nums[0];

        //second phase: Finding the entrance to the cycle, which is the duplicate number
        //reset turtle to the start of the vector
        while(turtle!=hare){
            turtle = nums[turtle];
            hare = nums[hare];
        }

        return turtle;

    }
};