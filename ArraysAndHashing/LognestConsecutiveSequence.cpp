//
// Created by Joel Jose Ginga on 25/02/2024.
//
/**
 * Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

   You must write an algorithm that runs in O(n) time.



    Example 1:
    Input: nums = [100,4,200,1,3,2]
    Output: 4
    Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

    Example 2:
    Input: nums = [0,3,7,2,5,8,4,6,0,1]
    Output: 9
 */

class LongestConsecutiveSequence {
public:
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int maxLength=0;

        for(auto num : set){
            //if the previous number is not present, then is the start of a sequence
            if(set.find(num-1)==set.end()){
                //we count the size of the sequence
                int curr = num, count = 0;
                while(set.find(num++) != set.end())
                    count++;
                maxLength = maxLength > count ? maxLength : count;
            }
        }
        return maxLength;
    }
};
};