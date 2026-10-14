// Q] Minimum Sum of Absolute Differences of Pairs ?

// Given two arrays a and b of equal length, pair each element of array a to an element in array b, such that the sum of the absolute differences of all the pairs is minimum

// Examples:
// Input: a = [4, 1, 8, 7], b = [2, 3, 6, 5]
// Output: 6
// Explanation:
// If we take the pairings as (1,2), (4,3), (7,5), and (8,6), the sum will be S = |1 - 2| + |4 - 3| + |7 - 5| + |8 - 6| = 6.
// It can be shown that this is the minimum sum we can get.


// Input: a = [4, 1, 2], b = [2, 4, 1]
// Output: 0
// Explanation: If we take the pairings as (4,4), (1,1), and (2,2), the sum will be S = |4 - 4| + |1 - 1| +|2 - 2| = 0. 
// It can be shown that this is the minimum sum we can get.


// Constraints:
// 1 ≤ a.size() == b.size() ≤ 105
// 0 ≤ a[i] ≤ 104
// 0 ≤ b[i] ≤ 104



// Solution Of This Question :-

class Solution {
  public:
    int findMinSum(vector<int>& a, vector<int>& b) {
        // code here
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int n = a.size();
        int n1 = b.size();
        int diff = 0;
        int sum = 0;
        int i = 0;
        int j = 0;
        
        while(i < n && j < n1){
            diff = abs(a[i] - b[j]);
            sum += diff;
            i++;
            j++;
        }
        return sum;
    }
};