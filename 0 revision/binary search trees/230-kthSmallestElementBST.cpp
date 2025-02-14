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
    void inorderTraversal(TreeNode* root, vector<int>& inorder){
        if(root==nullptr) return;

        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);

        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        inorderTraversal(root, inorder);

        return inorder[k-1];
    }
};

// inorder traversal gives me elements in sorted order.
// just get its inorder traversal in a vector & give.