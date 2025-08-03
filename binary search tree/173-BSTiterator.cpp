class BSTIterator {
public:
    TreeNode* temp;
    vector<int> inorder;
    int i=-1;

    BSTIterator(TreeNode* root) {
        temp = root;
        inorderTraversal(root, inorder);
    }

    void inorderTraversal(TreeNode* root, vector<int> &inorder){
        if(!root) return;

        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);

        return;
    }
    
    int next() {
        i++;
        return inorder[i];
    }
    
    bool hasNext() {
        if(i+1 < inorder.size()) return true;
        return false;
    }
};