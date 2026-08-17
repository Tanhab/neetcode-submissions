#include <print>
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> original;
        unordered_map<char,int> freq;
        for(char c : s1){
            original[c] += 1;
        }
        int l = 0, r = -1, k = s1.size(), n = s2.size();
        while(r<n){
            if(r-l+1 < k){
                r++;
                freq[s2[r]]++;
            }else if(r-l+1 == k){
                if(original == freq) 
                return true;
                if(freq[s2[l]] == 1)
                    freq.erase(s2[l]);
                else freq[s2[l]]--;
                l++;
            }
            // for(auto& [key, value] : freq){
            //     print("{} - {} * ", key, value);
            // }
            // println("\n{} = {}", l, r);

        }
        return false;

    }
};
