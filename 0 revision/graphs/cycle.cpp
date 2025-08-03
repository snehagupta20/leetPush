bool dfs(int node, int parent, vector<bool>& visited, vector<vector<int>>& adj){
        visited[node] = true;
        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]){
                if(dfs(adj[node][i], node, visited, adj)){
                    return true;
                }
            }
            else if(adj[node][i]!=parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        vector<bool> visited(adj.size(),false);
        for(int i=0;i<adj.size();i++){
            if(!visited[i]){
                if(dfs(i, -1, visited, adj)){
                    return true;   
                }
            }
        }
        return false;
    }