#include <print>
class Solution {
public:
    vector<string> chess;
    vector<vector<string>> ans;
    int sz;
    bool check(int x, int y){
        // row col
        for(int i=0; i<sz; i++){
                if(chess[i][y] == 'Q')
                    return false;
                if(chess[x][i] == 'Q')
                    return false;
        }
        int add = x+y, sub = x-y;
        for(int i = 0; i<sz; i++){
            for(int j=0; j<sz; j++){
                if(i+j == add || i-j == sub)
                    if(chess[i][j] == 'Q')
                        return false;
            }
        }
        return true;

    }
    /*
    00 01 02 03
    10 11 12 13
    20 21 22 23
    30 31 32 33
    */

    void backtrack(int r){
        if(r == sz ) {
            ans.push_back(chess);
            return;
        }
        //println("{}", r);
        for(int c = 0; c < sz; c++){
            if(check(r,c)){
                chess[r][c] = 'Q';
                backtrack(r+1);
                chess[r][c] = '.';
            }
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        for(int i = 0 ; i< n; i++){
           chess.push_back(string(n,'.'));
        }
        sz = n;
        backtrack(0);
        return ans;

    }
};
