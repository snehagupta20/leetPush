vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        vector<int> bfs;
        vector<bool> visited(adj.size(), false);
        queue<int> q;
        
        q.push(0); //bfs starts from vertex 0
        visited[0]=true;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            
            // add neighbors of curr node to queue
            for(int i=0;i<adj[node].size();i++){
                if(!visited[adj[node][i]]){
                    q.push(adj[node][i]);
                    visited[adj[node][i]]=true;
                }
            }
        }
        
        return bfs;
    }