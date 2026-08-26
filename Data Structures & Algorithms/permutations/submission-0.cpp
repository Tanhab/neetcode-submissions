class Solution {
   public:
    vector<vector<int>> ans;
    int n;
    void backtrack(vector<int> cur, vector<int>& nums, int mask) {
        if (n == cur.size()) {
            ans.push_back(cur);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                cur.push_back(nums[i]);
                backtrack(cur, nums, mask | (1 << i));
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        backtrack({}, nums, 0);
        return ans;
    }
};
