//
// Created by Joel Jose Ginga on 13/03/2024.
//
/**
 *  You are given an array prices where prices[i] is the price of a given stock on the ith day.
    You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

    Example 1:
    Input: prices = [7,1,5,3,6,4]
    Output: 5
    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
    Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

    Example 2:
    Input: prices = [7,6,4,3,1]
    Output: 0
    Explanation: In this case, no transactions are done and the max profit = 0.
 *
*/

class BestTimeToBuyAndSellStock {
public:
    //Time Complexity - O(n) - the algorithm iterates throught the array once
    // performing constat-time operations

    //space complexity - O(1) - the algorithm uses a constant amount of extra space
    //that remains the same dispite of the size of the input array
    int maxProfit(vector<int>& prices) {

        //minimum price
        int m = prices[0];
        //maximum profit
        int profit = 0;

        //this is very straight forward, at each iteration we compute and keep track
        //of the minimum price (m) and the maximum profit(profit)
        for(int i = 1 ; i < prices.size() ; i++){
            m = min(prices[i], m);
            profit = max(prices[i]-m, profit);
        }

        return profit;
    }
};