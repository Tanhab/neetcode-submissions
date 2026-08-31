class Solution {
   public:
    vector<int> mem;
    int dp(int i, vector<int>& nums) {
        if (i >= nums.size()) return 0;
        if (mem[i] != -1) return mem[i];

        return mem[i] = max(dp(i + 1, nums), nums[i] + dp(i + 2, nums));
    }
    int rob(vector<int>& nums) {
        mem.assign(nums.size(), -1);
        return dp(0, nums);
    }
};
