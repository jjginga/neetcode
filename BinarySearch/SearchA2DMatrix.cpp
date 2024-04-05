//
// Created by Joel Jose Ginga on 31/03/2024.
//
/**
 *You are given an m x n integer matrix matrix with the following two properties:
 *Each row is sorted in non-decreasing order.
 *The first integer of each row is greater than the last integer of the previous row.
 *Given an integer target, return true if target is in matrix or false otherwise.
 *
 *You must write a solution in O(log(m * n)) time complexity.
 *
 *Example 1:
 *Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 *Output: true
 *
 *Example 2:
 *Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
 *Output: false
*/

class SearchA2DMatrix {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int start = 0 , end = n * m - 1;

        while(start <= end){
            int middle = start + (end-start)/2;
            int middleValue = matrix[middle/m][middle%m];
            if(middleValue==target) return true;

            if(middleValue<target){
                start = middle + 1;
                continue;
            }

            end = middle - 1;
        }
        return false;
    }
};