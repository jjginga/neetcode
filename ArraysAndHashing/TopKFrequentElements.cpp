//
// Created by Joel Jose Ginga on 23/02/2024.
//

/**
 * Given an integer array nums and an integer k,
 * return the k most frequent elements.
 * You may return the answer in any order.

    Example 1:
    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]

    Example 2:
    Input: nums = [1], k = 1
    Output: [1]
 */

class TopKFrequentElements {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        std::unordered_map<int,int> map;

        for(auto& i : nums) ++map[i];

        //create a vector with the pairs of integers and their frequencies
        std::vector<std::pair<int, int>> elements(frequency.begin(), frequency.end());

        //order the elements according to the frequency
        std::sort(elements.begin(), elements.end(),
                  [](const std::pair<int, int>& a, const std::pair<int, int>& b){
                      return a.second > b.second;});

        std::vector<int> topK;
        for (int i = 0; i < k ; ++i)
            topK.push_back(elements[i].first);

        return topK;
    }
};