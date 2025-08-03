vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
    // Code here
    vector<vector<int>> adj(V);
    for(int i=0;i<edges.size();i++){
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
    return adj;
}

// gfg ques : PRINT ADJACENCY LIST 
