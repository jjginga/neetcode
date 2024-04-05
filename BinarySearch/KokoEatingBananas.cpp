//
// Created by Joel Jose Ginga on 05/04/2024.
//
/**
 * Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and
 * will come back in h hours.
 *
 * Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k
 * bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any
 * more bananas during this hour.
 *
 * Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
 *
 * Return the minimum integer k such that she can eat all the bananas within h hours.
 *
 * Example 1:
 * Input: piles = [3,6,7,11], h = 8
 * Output: 4
 * Explanation: With the eating speed of 4 bananas/hour, Koko can eat all bananas within 8 hours.
 *
 * Example 2:
 * Input: piles = [30,11,23,4,20], h = 5
 * Output: 30
 * Explanation: With the eating speed of 30 bananas/hour, Koko can eat all bananas within 5 hours.
 *
 * Example 3:
 * Input: piles = [30,11,23,4,20], h = 6
 * Output: 23
 * Explanation: With the eating speed of 23 bananas/hour, Koko can eat all bananas within 6 hours.
 */
#include <vector>
#include <algorithm>

class KokoEatingBananas {
private:
    //helper function to calculate total time to eat all bananas at a given speed
    int getTimeToEat(const vector<int>& piles, int speed){
        int time = 0;
        for(auto pile : piles)
            //for each pile, add the time to eat it at the current speed (rounding up)
            time += (pile + speed - 1)/speed;
        return time;
    }

public:
    //main function to find the minimum eating speed to finish all bananas within h hours
    int minEatingSpeed(vector<int>& piles, int h) {
        int minSpeed = 1; //minimum possible speed
        int maxSpeed = *max_element(piles.begin(), piles.end()); //maximum speed is the size of the largest pile

        //binary search to find the minimum speed
        while(maxSpeed > minSpeed){
            int middle = minSpeed + (maxSpeed - minSpeed) / 2; //calculate the middle speed

            int timeToEatAll = getTimeToEat(piles, middle); //calculate total time to eat all bananas at middle speed

            //if total time is more than h, need to increase speed
            if(timeToEatAll > h){
                minSpeed = middle + 1;
                continue;
            }

            //otherwise, try to decrease the speed to find the minimum
            maxSpeed = middle;

        }

        //return the minimum speed found
        return minSpeed;
    }
};