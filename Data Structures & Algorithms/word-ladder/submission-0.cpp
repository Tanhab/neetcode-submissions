class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> wordList) {
        int x = -1;
        int y = -1;
        for(int i = 0; i< wordList.size(); i++){
            if(wordList[i] == beginWord)
                x = i;
            if(wordList[i] == endWord)
                y = i;
        }
        if(x==-1){
            wordList.push_back(beginWord);
             x = ssize(wordList)-1;
        }
        if(y==-1){
           return 0;
        }
        int n = wordList.size();
        int m = wordList[0].size();
        
        
        vector<vector<int>> adj(n);
        for(int i = 0; i<n ;i++){
            for(int j = 0; j<n; j++){
                int cnt = 0;
                for (int k = 0; k<m; k++){
                    if(wordList[i][k]!=wordList[j][k])
                        cnt++;
                }
                if(cnt == 1 && i!=j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<int> dist(n,-1);
        queue<int>q;
        dist[x] = 1;
        q.push(x);
        while(!q.empty()){
            int a = q.front();
            q.pop();
            if(a == y) return dist[y];
            for(int nei : adj[a]){
                if(dist[nei] == -1){
                    dist[nei] = dist[a]+1;
                    q.push(nei);
                }

            }
        }

        return 0;

        
    }
};
