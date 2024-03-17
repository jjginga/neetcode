//
// Created by Joel Jose Ginga on 16/03/2024.
//

/**
*
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
 * In other words, return true if one of s1's permutations is the substring of s2.
 *
 * Example 1:
 * Input: s1 = "ab", s2 = "eidbaooo"
 * Output: true
 * Explanation: s2 contains one permutation of s1 ("ba").
 *
 * Example 2:
 * Input: s1 = "ab", s2 = "eidboaoo"
 * Output: false
 * */

class PermutationInString {
public:
    bool checkInclusion(string s1, string s2) {

        //if s1 is longer thatn s2 then it is impossible for s2 to contain a permutation of s1
        if (s1.length() > s2.length()) return false;

        //initialize the left counter and the arrays to contain the count
        //since we are dealing with lower case english letters we only need 26
        int left = 0, s1Count[26]={0}, s2Count[26]={0};

        //count the frequency of each letter in s1
        for(auto ch : s1)
            s1Count[ch-'a']++;

        //in the first window, count the frequency of each letter in s2
        for(int i = 0 ; i < s1.length() ; i++)
            s2Count[s2[i]-'a']++;

        //slide the window across s2 and check if any window is a permutation of s1
        for(int right = s1.length() ; right <= s2.length() ; right++){

            bool isPermutation = true;
            //compare the count of each letter
            for(int j = 0 ; j < 26 ; j++){
                //if the windows don't match then it is not a permutation
                if(s1Count[j]!=s2Count[j]){
                    isPermutation = false;
                    break;
                }
            }

            //if the permutation is found we return true
            if(isPermutation) return true;

            //if we are at the end of s2 we break
            if(right == s2.length()) break;

            //we slide the window and adjust the count in the array
            s2Count[s2[right]-'a']++;
            s2Count[s2[left++]-'a']--;

        }
        return false;
    }
};


/*class PermutationInString {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.length() > s2.length()) return false;

        int left = 0;
        unordered_map<char, int> s1Map, s2Map;

        for(auto ch : s1)
            s1Map[ch]++;

        for(int i = 0 ; i < s1.length() ; i++)
            s2Map[s2[i]]++;

        for(int right = s1.length() ; right <= s2.length() ; right++){

            bool isPermutation = true;
            for(auto const& [key, val] : s1Map){
                if(s2Map.find(key) == s2Map.end() || s2Map[key] != val){
                    isPermutation = false;
                    break;
                }
            }

            if(isPermutation) return true;

            s2Map[s2[right]]++;
            s2Map[s2[left++]]--;

        }
        return false;
    }
};*/

/*
First iteration, this has complexity O(n*m)
in worst case we compare the length of s1 for each char of s2

class PermutationInString {
public:
    bool checkInclusion(string s1, string s2) {
        //if s1>s2 then it is false
        //iterate through s1
        //find first occurence of the char and see if the following chars are permutations of s1

        unordered_map<char, int> s1Map;

        //count occurrences
        for(auto ch : s1)
            s1Map[ch]++;

        for(auto const& [ch, _] : s1Map){

            int pos = -1;
            //for each occurrence of the char
            while( (pos = s2.find(ch, pos+1)) < s2.length()){

                unordered_map<char, int> s2Map = s1Map;
                //we check if the  substring of s2 is a permutation of s1
                for(int j = pos ; j < pos+s1.length() ; j++){
                    if(s2Map.find(s2[j])==s2Map.end()) break;
                    s2Map[s2[j]]--;
                    if(s2Map[s2[j]] == 0) s2Map.erase(s2[j]);
                }

                if(s2Map.empty()) return true;
            }



        }
        return false;
    }
};*/
