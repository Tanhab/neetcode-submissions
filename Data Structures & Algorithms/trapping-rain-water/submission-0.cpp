#include <print>

class Solution {
public:
    int trap(vector<int>& height) {
        int n = ssize(height);
        int ans = 0, cur = 0;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        for(int i = 0; i<n ;i++){
            if(i==0) left[0] = height[0];
            else{
                left[i] = max(height[i-1], left[i-1]);
            }
        }
        for(int i = n-1; i >=0 ; i--){
            if(i==n-1) right[i] = height[i];
            else right[i] = max(height[i+1], right[i+1]);
        }
        for(int i = 1; i<n-1; i++){
           // println("{} -> {} {} {}", i, left[i], right[i], (min(left[i], right[i]) - height[i]));
            ans += max(0,(min(left[i], right[i]) - height[i]));
        }
        return ans;
    }
};
