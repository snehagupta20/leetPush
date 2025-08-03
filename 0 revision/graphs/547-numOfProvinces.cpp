class Solution {
public:
    void bfs(vector<bool>& visited, vector<vector<int>>& isConnected, queue<int>& q){
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i=0;i<isConnected[node].size();i++){
                if(!visited[i] && isConnected[node][i]==1){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false);
        int provinces = 0;
        queue<int> q;

        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                // bfs just to mark all of the connected notes visited.
                visited[i] = true;
                q.push(i);
                bfs(visited, isConnected, q);
                provinces++;
            }
        }

        return provinces;
    }
};