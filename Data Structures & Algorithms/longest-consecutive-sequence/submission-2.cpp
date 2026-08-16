class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int x: nums){
            s.insert(x);
        }
        int ans = 0;
        for(int x : s){
            if(!s.contains(x-1)){
                int temp = 0;
                while(s.contains(x)){
                    temp++, x++;
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};
