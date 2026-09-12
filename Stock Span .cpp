// Input: arr[] = [100, 80, 90, 120]
// Output: [1, 1, 2, 4]
// Explanation: Consider each day one by one:
// Day 1 (100): Span = 1.
// Day 2 (80): Span = 1 because the previous price (100) is greater than 80.
// Day 3 (90): Span = 2 because 80 ≤ 90, but 100 > 90.
// Day 4 (120): Span = 4 because 100, 80, and 90 are all less than or equal to 120.
// Hence, the output is [1, 1, 2, 4].


class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>ssp(n);
        stack<int>p;
        
        for(int i = 0; i < n; i++){
            while(p.size() > 0 && arr[p.top()] <= arr[i]) 
            p.pop();
            
            if(p.size() == 0){
                ssp[i] = i - (-1);
            }
            else{
                ssp[i] = i - p.top();
            }
            p.push(i);
        }
        return ssp;
    }
};