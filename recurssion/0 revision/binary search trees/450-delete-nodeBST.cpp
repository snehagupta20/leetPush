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
    TreeNode* findMin(TreeNode* root){
        if(root==nullptr) return root;
        while(root->left != nullptr){
            root = root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return root;
        if(root->val == key){
            if(!root->left && !root->right){
                // delete
                delete root;
                return nullptr;
            }
            if(!root->left && root->right){
                // right child
                TreeNode* rightChild = root->right;
                delete root;
                return rightChild;
            }
            if(root->left && !root->right){
                // left child
                TreeNode* leftChild = root->left;
                delete root;
                return leftChild;
            }
            if(root->left && root->right){
                // delete find max (right) && min of (left);
                TreeNode* temp = findMin(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
                return root;
            }
        }
        if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        if(root->val < key){
            root->right = deleteNode(root->right, key);
        }

        // return;
        return root;
    }
};

//       6
//    4    7
//  2   5    8
// 1 3
