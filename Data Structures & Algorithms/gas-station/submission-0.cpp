#include <print>
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // for(int i = 0; i< gas.size(); i++){
        //     cout << gas[i]-cost[i] << " ";
        // }
        // //cout << endl;
        // for(int i = 0; i< gas.size(); i++){
        //     cout << gas[i]-cost[i] << " ";
        // }
        // cout << endl;
        int last = -1, sum = 0, count = 0, n = gas.size();
        for(int i = 0; i< n*2; i++){
            int idx = (i%n);
            if(sum+ (gas[idx] - cost[idx]) <0){
                sum = 0;
                count = 0;
                last = -1;
                continue;
            }
            if(last == -1) last = idx;
            sum+=(gas[idx] - cost[idx]);
            count++;
           //print("{} - {} - {} - {} - {}", i, )
            if(count == n) return last;
        }
        return -1;

        
    }
};
