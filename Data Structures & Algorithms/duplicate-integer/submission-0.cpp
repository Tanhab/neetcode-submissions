class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = ssize(nums);
        unordered_map<int,bool> mp;
        for(int x : nums){
            if(mp.contains(x))
                return true;
            mp[x] = true;
        }
        return false;
    }
};