class KthLargest {
public:
    int kk = 0;
    multiset<int> s;
    KthLargest(int k, vector<int>& nums) {
        s = multiset(nums.begin(), nums.end());
        kk = k;
    }
    
    int add(int val) {
        s.insert(val);
        return *next(s.end(), -kk );
    }
};
