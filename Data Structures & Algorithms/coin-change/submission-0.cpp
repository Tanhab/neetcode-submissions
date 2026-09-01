class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        const int inf = INT_MAX/4;
        vector<int> a(amount+5, inf);
        for(int c: coins){
            if(c <= amount )
                a[c]= 1;
        }
        for(int i = 1; i<=amount; i++){
            if(a[i]!=inf){
                for(int c : coins){
                    if((long long)i+c <= amount)
                        a[i+c] = min(a[i+c],a[i] + 1);
                }
            }
        }
        // for(int i = 0; i<= amount; i++){
        //     cout << i << " -> " << a[i] << endl;
        // }

        return a[amount] == inf ? - 1 : a[amount];
        
    }
};
