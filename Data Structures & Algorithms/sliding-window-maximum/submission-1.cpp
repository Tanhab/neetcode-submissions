class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s;
        vector<int> ans;
        for (int i = 0; i < ssize(nums); i++) {
            s.insert(nums[i]);
            if (i < k - 1) continue;
            ans.push_back(*s.rbegin());
            s.erase(s.find(nums[i-k+1]));
        }
        return ans;
    }
};
