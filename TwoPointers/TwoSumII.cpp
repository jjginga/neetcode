//
// Created by Joel Jose Ginga on 05/03/2024.
//

/**
* Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
  Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
  The tests are generated such that there is exactly one solution. You may not use the same element twice.
  Your solution must use only constant extra space.

  Example 1:
  Input: numbers = [2,7,11,15], target = 9
  Output: [1,2]
  Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

  Example 2:
  Input: numbers = [2,3,4], target = 6
  Output: [1,3]
  Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

  Example 3:
  Input: numbers = [-1,0], target = -1
  Output: [1,2]
  Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
*/

class TwoSumII {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        //initialize the pointers
        int left = 0 , right = numbers.size()-1;


        while(left < right){
            //calculate the sum of the two pointed values
            int sum = numbers[left]+numbers[right];

            //if the sum matches the target, we return the original indices of the two
            if(sum == target)
                return { left+1, right+1};

            //if the sum is less than the target, move the left pointer to the right
            //that is, we increase the left value
            if(sum < target){
                left++;
                continue;
            }

            //if the sum is greater than the target, we move the right pointer to the left
            right--;

        }

        return {};
    }
};