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
    TreeNode* buildBST(vector<int>& preorder, int& idx, int lower, int upper) {
        if (idx >= preorder.size() || preorder[idx] < lower || preorder[idx] > upper) {
            return nullptr;
        }

        int val = preorder[idx++];
        TreeNode* root = new TreeNode(val);
        root->left = buildBST(preorder, idx, lower, val);  // Left subtree: values < root
        root->right = buildBST(preorder, idx, val, upper); // Right subtree: values > root

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0; // Start from the first element of preorder
        return buildBST(preorder, idx, INT_MIN, INT_MAX);
    }
};
