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
    int d = 0;
    int depth(TreeNode* root){
        if(root==nullptr) return 0;

        int left = depth(root->left);
        int right = depth(root->right);

        d=max(d, left+right);

        return max(left, right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return d;
    }
};

// left depth + right depth