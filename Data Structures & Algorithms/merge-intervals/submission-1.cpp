class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int low = intervals[0][0], high= intervals[0][1];
        int i=1, n = intervals.size();
        vector<vector<int>> ans;
        while(i < n){
            int curL = intervals[i][0], curH = intervals[i][1];
            if(high < curL){
                ans.push_back({low, high});
                low = curL, high = curH;
                i++;
                continue;
            }
            low = min(low, curL);
            high = max(high, curH);
            i++;
        }
        if(high >= intervals[n-1][1])  ans.push_back({low, high});
        return ans;
    }
};
