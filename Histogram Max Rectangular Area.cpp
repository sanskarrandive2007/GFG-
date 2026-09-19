// Q] Histogram Max Rectangular Area :-

// Given a histogram represented by an array arr[], where each element of the array denotes the height of the bars in the histogram. All bars have the same width of 1 unit.

// Find the largest rectangular area possible in the given histogram, where the rectangle can be formed using a number of contiguous bars.

// Input: arr[] = [60, 20, 50, 40, 10, 50, 60]
//  Largest-Rectangular-Area-in-a-Histogram
// Output: 100
// Explanation: We get the maximum by picking bars highlighted above in green (50, and 60). The area is computed = 50 * 2 = 100.

// Constraints:

// 1 ≤ arr.size() ≤ 105
// 0 ≤ arr[i] ≤ 104

// Approach:
// 1. Create a stack to keep track of the indices of the bars.
// 2. Iterate through each bar in the histogram.
// 3. For each bar, while the stack is not empty and the current bar is shorter than the bar at the index stored at the top of the stack:
//    a. Pop the top index from the stack.
//    b. Calculate the area with the popped index as the smallest (or minimum height) bar.
//    c. The width of the rectangle is determined by the current index and the index of the new top of the stack.
// 4. Push the current index onto the stack.
// 5. After iterating through all bars, pop any remaining bars from the stack and calculate the area.
// 6. Return the maximum area found.


// Solution Of This Question :-

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int>nse(n);
        stack<int>p;
        
        for(int i = n - 1; i >= 0; i--){
            while(p.size() > 0 && arr[p.top()] >= arr[i]) p.pop();
            
            if(p.size() == 0){
                nse[i] = n;
                
            }
            else{
                nse[i] = p.top();
            }
            p.push(i);
        }
        
        vector<int>pse(n);
        stack<int>st;
        
        for(int i = 0; i < n; i++){
            while(st.size() > 0 && arr[st.top()] >= arr[i]) st.pop();
            
            if(st.size() == 0){
                pse[i] = -1;
            }
            else{
                pse[i] = st.top();
            }
            st.push(i);
        }
        int max1 = 0;
        
        for(int i = 0; i < n; i++){
            int width = nse[i] - pse[i] - 1;
            int height = arr[i];
            
            max1 = max(max1, width * height);
        }
        return max1;
    }
};
