//
// Created by Joel Jose Ginga on 06/04/2024.
//

/**
 *There is an integer array nums sorted in ascending order (with distinct values).
 *
 *Prior to being passed to your function, nums is possibly rotated at an unknown
 *pivot index k (1 <= k < nums.length) such that the resulting array is
 *[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
 *For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
 *
 *Given the array nums after the possible rotation and an integer target,
 *return the index of target if it is in nums, or -1 if it is not in nums.
 *
 *You must write an algorithm with O(log n) runtime complexity.
 *
 *Example 1:
 *Input: nums = [4,5,6,7,0,1,2], target = 0
 *Output: 4
 *
 *Example 2:
 *Input: nums = [4,5,6,7,0,1,2], target = 3
 *Output: -1
 *
 *Example 3:
 *Input: nums = [1], target = 0
 *Output: -1
 */

class SearchInRotatedSortedArray {
public:
    int search(vector<int>& nums, int target) {
        //if the array has only one element
        if(nums.size()==1) return nums[0] == target ? 0 : -1;

        int minPos = 0;
        int maxPos = nums.size()-1;

        while(minPos <= maxPos){

            int middle = minPos+(maxPos-minPos)/2;

            //check if we found the target position
            if(nums[middle] == target) return middle;

            //the right half is ordered
            if(nums[middle]<nums[maxPos]){
                //if target is on right half
                if(nums[middle]<target && nums[maxPos]>=target){
                    minPos = middle + 1;
                    continue;
                }

                //target is in the left half
                maxPos = middle - 1;
                continue;
            }

            //the left part is ordered
            //if the target is in the ordered half
            if(nums[middle]>target && nums[minPos]<=target){
                maxPos = middle-1;
                continue;
            }

            minPos = middle+1;

        }

        return -1;

    }
};