#include<print>
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = ssize(heights) - 1;
        int ans = 0;
        while(l<r){
            ans = max(ans, (r-l) * min(heights[l],heights[r]));
            //println("{} {} {}", l, r , ans);
            if(heights[l]<=heights[r]) l++;
            else r--;
        }
        return ans;
    }
};
