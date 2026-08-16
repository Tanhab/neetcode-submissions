class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        unordered_map<int, vector<int> > mp;
        for(int x : nums){
            freq[x] = freq[x] + 1;
        }
        for(auto& [key, val] : freq){
            mp[val].push_back(key);
        }
        int mx = ssize(nums);
        vector<int> ans;
        while(k){
            if(!mp.contains(mx))
            {
                mx--;
                continue;
            }  
            for(int x : mp[mx]){
                ans.push_back(x);
                k--;
                if(!k) return ans; 
            }
            mx--;
        }
        return ans;

    }
};
