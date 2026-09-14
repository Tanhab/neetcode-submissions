class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = 0;
        int n = nums.size();
        for(int i=0; i<n;i++){
            if(i<=mx){
                mx = max(i+nums[i],mx);
            }
        }
        return mx >= n-1;
    }
};
