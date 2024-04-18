//
// Created by Joel Jose Ginga on 10/04/2024.
//
 /**
 *Given two sorted arrays nums1 and nums2 of size m and n respectively,
 *return the median of the two sorted arrays.
 *
 *The overall run time complexity should be O(log (m+n)).
 *
 *Example 1:
 *Input: nums1 = [1,3], nums2 = [2]
 *Output: 2.00000
 *Explanation: merged array = [1,2,3] and median is 2.
 *
 *Example 2:
 *Input: nums1 = [1,2], nums2 = [3,4]
 *Output: 2.50000
 *Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 */

 class MedianOfTwoSortedArrays {
 public:
     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         //we perform the binary search based on the smaller array
         if(nums2.size()<nums1.size()) return findMedianSortedArrays(nums2,nums1);

         //size of the arrays
         int n = nums1.size(), m = nums2.size();
         //initial search range in nums1
         int low = 0, high = n;

         while(low <= high){
             //partition index in nums1
             int nIndex = (low + high) / 2;
             //partition index in nums2
             int mIndex = (n + m +1) / 2 - nIndex;

             //maximum value on the left side of the partition in nums1 or INT_MIN if at the beginning
             int maxLeftN = (nIndex == 0) ? INT_MIN : nums1[nIndex-1];
             //minimum value on the right of the partition in nums1 or INT_MAX if at the end
             int minRightN = (nIndex == n) ? INT_MAX : nums1[nIndex];

             int maxLeftM = (mIndex == 0) ? INT_MIN : nums2[mIndex-1];
             int minRightM = (mIndex == m) ? INT_MAX : nums2[mIndex];

             //we check if partition is vallid
             if(maxLeftN <= minRightM && maxLeftM <= minRightN)
                 return (n+m) % 2 != 0 ? max(maxLeftM, maxLeftN)
                                       : (max(maxLeftM, maxLeftN) + min(minRightM, minRightN))/2.0;

             //partition in nums1 is too far to the right
             if(maxLeftN > minRightM){
                 high = nIndex - 1;
                 continue;
             }

             //otherwise we need more elements of num1 in the bottom half
             low = nIndex + 1;;
         }

         return -1;
     }
 };