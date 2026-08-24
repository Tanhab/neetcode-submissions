class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> v(2005,0);
        for(int x : nums){
            v[x+1000]++; 
        }
        
        int cur = 0;
        int i = 2000;
        while(cur<=k){
            if(v[i]>0){
                cur+=v[i];
            }
            if(cur>=k)
                return i -1000;
            i--;
        }
    }
};
