//
// Created by Joel Jose Ginga on 06/04/2024.
//
/**
 * Design a time-based key-value data structure that can store multiple values for the
 * same key at different time stamps and retrieve the key's value at a certain timestamp.
 *
 * Implement the TimeMap class:
 *
 *  * TimeMap() Initializes the object of the data structure.
 *  * void set(String key, String value, int timestamp) Stores
 *  the key key with the value value at the given time timestamp.
 *  + String get(String key, int timestamp) Returns a value such
 *  that set was called previously, with timestamp_prev <= timestamp.
 *  If there are multiple such values, it returns the value associated
 *  with the largest timestamp_prev. If there are no values, it returns "".
 *
 *
 * Example 1:
 * Input
 * ["TimeMap", "set", "get", "get", "set", "get", "get"]
 * [[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
 * Output
 * [null, null, "bar", "bar", null, "bar2", "bar2"]
 *
 * Explanation
 * TimeMap timeMap = new TimeMap();
 * timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
 * timeMap.get("foo", 1);         // return "bar"
 * timeMap.get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
 * timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
 * timeMap.get("foo", 4);         // return "bar2"
 * timeMap.get("foo", 5);         // return "bar2"
 * */

class TimeMap {
private:
    //we user a map to sotre a vector of pairs, each containing the timestamp and the corresponding value
    unordered_map<string,vector<pair<int, string>>> map;

public:
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        //if the key does not exist we initialize it with an empty vector
        if(map.find(key)==map.end()){
            vector<pair<int, string>> vector;
            map[key]=vector;
        }

        //append the new timestamp and value to the vector associated with the key
        map[key].push_back(make_pair(timestamp,value));


    }

    string get(string key, int timestamp) {
        //if the key does not exist we return an empty string
        if(map.find(key)==map.end())
            return "";

        if(map[key][0].first == timestamp) return map[key][0].second;

        //if the timestamp is before the first we return empty string
        if(map[key][0].first > timestamp) return "";
        //if the timestamp is after the first we return the value
        if(map[key][map[key].size()-1].first <= timestamp) return map[key][map[key].size()-1].second;

        //we use binary search to find the timestamp closest to the requested timestamp
        int minPos = 0, maxPos=map[key].size()-1;
        while(minPos<maxPos){
            int middle = minPos+(maxPos-minPos)/2;
            int middleVal = map[key][middle].first;

            if(middleVal == timestamp) return map[key][middle].second;

            if(middleVal<timestamp){
                minPos = middle + 1;
                continue;
            }

            maxPos = middle;
        }

        return map[key][minPos-1].second;
    }
};