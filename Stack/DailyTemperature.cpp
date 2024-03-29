//
// Created by Joel Jose Ginga on 27/03/2024.
//

/**
*Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i]
* is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day
* for which this is possible, keep answer[i] == 0 instead.
*
*Example 1:
*Input: temperatures = [73,74,75,71,69,72,76,73]
*Output: [1,1,4,2,1,1,0,0]
*
*Example 2:
*Input: temperatures = [30,40,50,60]
*Output: [1,1,1,0]
*
*Example 3:
*Input: temperatures = [30,60,90]
*Output: [1,1,0]
 */

class DailyTemperature {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<int> stack;


        for(int i = temperatures.size()-1 ; i >= 0 ; i--){

            //we search in the stack one index bigger than the current temperature
            while(!stack.empty() && temperatures[i] >= temperatures[stack.top()])
                stack.pop();

            if(!stack.empty())
                res[i] = stack.top()-i;

            stack.push(i);
        }
        return res;
    }
};

/* Fist approach, accepted but slow
class DailyTemperature{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), INT_MAX);
        int maxTemp = INT_MIN;
        unordered_map<int, int> map;
        for(int i = temperatures.size()-1 ; i >= 0 ; i--){
            map[temperatures[i]]=i;
            if(temperatures[i]>=maxTemp){
                maxTemp = max(temperatures[i], maxTemp);
                res[i] = 0;
                continue;
            }

            for ( const auto &[key, value]: map ) {
                if(key>temperatures[i])
                    res[i]=min(res[i], value-i);
            }
        }
        return res;
    }
};
 */