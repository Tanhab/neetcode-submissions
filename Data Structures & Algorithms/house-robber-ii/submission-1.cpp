class Solution {
   public:
    vector<int> mem;
    int dp(int i, int n, vector<int>& nums) {
        if (i >=n) return 0;
        if (mem[i] != -1) return mem[i];

        return mem[i] = max(dp(i + 1,n, nums), nums[i] + dp(i + 2,n, nums));
    }
    int rob(vector<int>& nums) {
        int n = ssize(nums);
        if(n==1) return nums[0];
        mem.assign(n, -1);
        int ans = dp(0,n-1, nums);
        mem.assign(n, -1);
        return max(ans , dp(1,n,nums));
    }
};
