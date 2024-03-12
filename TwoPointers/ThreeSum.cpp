//
// Created by Joel Jose Ginga on 08/03/2024.
//
/**
* Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
  Notice that the solution set must not contain duplicate triplets.

  Example 1:
  Input: nums = [-1,0,1,2,-1,-4]
  Output: [[-1,-1,2],[-1,0,1]]
  Explanation:
  nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
  nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
  nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
  The distinct triplets are [-1,0,1] and [-1,-1,2].
  Notice that the order of the output and the order of the triplets does not matter.

  Example 2:
  Input: nums = [0,1,1]
  Output: []
  Explanation: The only possible triplet does not sum up to 0.

  Example 3:
  Input: nums = [0,0,0]
  Output: [[0,0,0]]
  Explanation: The only possible triplet sums up to 0.
*/

class ThreeSum {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //we sort the array
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        //iterate over it
        for(int i = 0 ; i < nums.size() ; i++) {
            //if is the same number has the previous there is no neeed to check again
            if(i>0 && nums[i]==nums[i-1])
                continue;

            //we create the two pointers
            int left = i+1, right = nums.size()-1;

            while(left < right){
                int sum = nums[i]+nums[left]+nums[right];

                //if the sum is more than zero we move the right
                if(sum>0){
                    right--;
                    continue;
                }

                //if the sum is less than zero we move the left
                if(sum<0){
                    left++;
                    continue;
                }

                //the sum is zero and we add it to the vector
                res.push_back({nums[i], nums[left], nums[right]});

                //we adjust the pointers to avoid duplicates
                while(left<right && nums[left]==nums[left+1]) left++;
                while(left<right && nums[right-1]==nums[right]) right--;
                left++;
                right--;
            }
        }
        return res;
    }
};