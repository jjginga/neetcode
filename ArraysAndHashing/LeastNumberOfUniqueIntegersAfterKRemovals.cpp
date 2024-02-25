//
// Created by Joel Jose Ginga on 16/02/2024.
//

class LeastNumber{
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        //create a map where to count the frequency of each integer in the array
        std::unordered_map<int,int> frequency;

        for( auto num : arr)
            ++frequency[num];

        //create a vector with the pairs of integers and their frequencies
        std::vector<std::pair<int, int>> elements(frequency.begin(), frequency.end());

        //order the elements according to the frequency
        std::sort(elements.begin(), elements.end(),
            [](const std::pair<int, int>& a, const std::pair<int, int>& b){
                return a.second < b.second;});

        //create ordered vector from the least frequent element
        std::vector<int> orderedByFrequency;
        for (const auto& element : elements)
            for (int i = 0; i < element.second; ++i)
                orderedByFrequency.push_back(element.first);

        //remove the first n elements of the vector
        orderedByFrequency.erase(orderedByFrequency.begin(), orderedByFrequency.begin() +k);
        // Find the uniques in the array
        std::unordered_set<int> uniques(orderedByFrequency.begin(), orderedByFrequency.end());
        return uniques.size();
    }
};