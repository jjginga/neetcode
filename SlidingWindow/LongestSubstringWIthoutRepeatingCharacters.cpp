//
// Created by Joel Jose Ginga on 13/03/2024.
//
/**
* Given a string s, find the length of the longest substring without repeating characters.
 *
 * Example 1:
   Input: s = "abcabcbb"
   Output: 3
   Explanation: The answer is "abc", with the length of 3.

   Example 2:
   Input: s = "bbbbb"
   Output: 1
   Explanation: The answer is "b", with the length of 1.

   Example 3:
   Input: s = "pwwkew"
   Output: 3
   Explanation: The answer is "wke", with the length of 3.

    Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class LongestSubstringWithoutRepeatingCharacters {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, maxSize = 0;
        unordered_set<char> counter;

        //we use sliding window
        while(right < s.length()) {
            //if the character is not on set, we add it and check the size of the substring
            if(!counter.count(s.at(right))){
                counter.insert(s.at(right++));
                maxSize = max(right-left, maxSize );
                continue;
            }
            //if the character is on set we move the start of the window right
            counter.erase(s.at(left++));
        }
        return maxSize;
    }
};