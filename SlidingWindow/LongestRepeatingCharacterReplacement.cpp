//
// Created by Joel Jose Ginga on 16/03/2024.
//
/**
 * You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
   Return the length of the longest substring containing the same letter you can get after performing the above operations.

   Example 1:
   Input: s = "ABAB", k = 2
   Output: 4
   Explanation: Replace the two 'A's with two 'B's or vice versa.

   Example 2:
   Input: s = "AABABBA", k = 1
   Outut: 4
   Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
   The substring "BBBB" has the longest repeating letters, which is 4.
   There may exists other ways to achieve this answer too.
 */

class Solution {
public:
    int characterReplacement(string s, int k) {
        //we must find the longest substring with the same character + k different
        int left = 0, right = 0, maxSize = 0, maxFreq = 0;
        //we create a map to count the number of occurence of the chars
        unordered_map<char, int> map;


        while(right < s.length()){
            //we add the character on the right to the map
            map[s[right]]++;
            //update the moust frequent Char
            maxFreq = max(maxFreq, map[s[right]]);

            //if the number of chars that must be replaced is more than k then we move left
            if(right-left+1-maxFreq>k){
                map[s[left]]--;
                left++;
            }

            //finally we update the size and move right
            maxSize = max(maxSize, right-left+1);
            right++;
        }
        return maxSize;
    }
};