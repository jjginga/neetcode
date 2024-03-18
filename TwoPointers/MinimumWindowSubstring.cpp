//
// Created by Joel Jose Ginga on 18/03/2024.
//

/**Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 */

class MinimumWindowSubstring {
public:
    string minWindow(string s, string t) {

        if(t.length()>s.length()) return "";
        if(s==t) return s;

        int tCount[52]={0}, sCount[52]={0};
        int minLeft=0, minLength=INT_MAX;
        int left = 0 , found = 0;

        //we count the occurence of each character in t
        for(auto ch : t)
            tCount[getIndex(ch)]++;

        //we start by expanding the window to the right
        for(int right = 0 ; right < s.length() ; ++right){

            int index = getIndex(s[right]);

            sCount[index]++;

            //when we found a character of t in s we increase found
            if(sCount[index]<=tCount[index]) found++;

            //when all characters are found we try con contract the window on the left
            while(found == t.length()){
                //if is smaller than previous minumum window we update
                if(right-left+1 < minLength){
                    minLength = right - left + 1;
                    minLeft = left;
                }

                //otherwise we try removing a character on the left
                index = getIndex(s[left]);
                sCount[index]--;
                //if ths substring stops having all characters in c we decrease found essencially breaking the cycle
                if(sCount[index] < tCount[index]) found--;
                left++;
            }
        }


        return minLength == INT_MAX ? "" : s.substr(minLeft,minLength);


    }

    int getIndex(char ch){
        return ch>='a'? ch-'a': ch-'A'+26;
    }

};