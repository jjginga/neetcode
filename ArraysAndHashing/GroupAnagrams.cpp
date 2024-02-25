//
// Created by Joel Jose Ginga on 16/02/2024.
//
/**
* Given an array of strings strs, group the anagrams together. You can return the answer in any order.

    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

    Example 1:
    Input: strs = ["eat","tea","tan","ate","nat","bat"]
    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

    Example 2:
    Input: strs = [""]
    Output: [[""]]

    Example 3:
    Input: strs = ["a"]
    Output: [["a"]]
*/

class GroupAnagrams{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> values;
        for(auto str : strs){
            auto key = str;
            sort(key.begin(), key.end());
            map[key].push_back(str);
        }

        for(const auto& [key, value] : map)
            values.push_back(value);
        return values;

    }
};