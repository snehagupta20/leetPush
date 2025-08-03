void dfsTraversal(int node, vector<bool>& visited, vector<int>&dfs, vector<vector<int>>& adj){
        visited[node] = true;
        dfs.push_back(node);
        
        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]){
                dfsTraversal(adj[node][i], visited, dfs, adj);
            }
        }
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        vector<int> dfs;
        vector<bool> visited(adj.size(), false);
        
        dfsTraversal(0, visited, dfs, adj);
        
        return dfs;
    }