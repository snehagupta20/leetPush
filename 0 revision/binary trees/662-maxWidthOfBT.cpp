/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode* ,unsigned long long>> q;
        q.push({root, 1});

        unsigned long long width = 0;

        while(!q.empty()){
            int size = q.size();
            unsigned long long first, last;

            for(int i=0;i<size;i++){
                auto p = q.front();
                q.pop();
                TreeNode* curr = p.first;
                unsigned long long index = p.second;

                
                if(i==0){
                    first = index;
                }
                if(i==size-1){
                    last = index;
                }

                if(curr->left) q.push({curr->left, 2*index});
                if(curr->right) q.push({curr->right, 2*index+1});
            }

            width = max(width , last-first+1);
        }
        return width;
    }
};
