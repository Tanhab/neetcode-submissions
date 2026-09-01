class Solution {
public:
    unordered_set<string> ok;
    unordered_map<int,int> mem;

    int dp(int i, string& s){
        if(i==s.size()) return 1;
        if(i>s.size()) return 0;
        if(mem.contains(i)) return mem[i];
        if(s[i] == '0') return 0;
        if(i<s.size() -1 && ok.contains(s.substr(i,2))) 
            return mem[i] = dp(i+1,s) + dp(i+2,s);
        else return mem[i] = dp(i+1,s);
    }

    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        for(int i = 1; i<27; i++){
            ok.insert(to_string(i));
        }
        for(int i = 1; i<s.size(); i++){
            if(s[i] == '0' && (s[i-1] <= '0' || s[i-1] >= '3')) 
                return 0;
        }
        return dp(0,s);

    }
};
