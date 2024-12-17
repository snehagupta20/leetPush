class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mpp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto m = q.front();
            q.pop();
            TreeNode* node= m.first;
            int x= m.second.first;
            int y= m.second.second;

            mpp[x][y].insert(node->val);
            if(node->left){
                q.push({node->left,{x-1,y+1}});
                
            }
             if(node->right){
                q.push({node->right,{x+1,y+1}});
                
            }
        }
        
        vector<vector<int>> ans;
        for(auto z : mpp){
            vector<int> coloumn;
            for( auto w : z.second){
                coloumn.insert(coloumn.end(),w.second.begin(),w.second.end());
            }
            ans.push_back(coloumn);
        }
        return ans;
    }
};