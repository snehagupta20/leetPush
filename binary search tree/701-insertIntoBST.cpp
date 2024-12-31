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
    void insertIntoBSTHelper(TreeNode* &root, int val){
        if(root==nullptr) {
            root = new TreeNode(val);
            return;
        }
        if(root->val > val){
            if(root->left == nullptr) {
                TreeNode* temp = new TreeNode(val);
                root->left = temp;
            }
            return insertIntoBSTHelper(root->left, val);
        }
        if(root->val < val){
            if(root->right == nullptr) {
                TreeNode* temp = new TreeNode(val);
                root->right = temp;
            }
            return insertIntoBSTHelper(root->right, val);
        }

        return;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        insertIntoBSTHelper(root, val);
        return root;
    }
};