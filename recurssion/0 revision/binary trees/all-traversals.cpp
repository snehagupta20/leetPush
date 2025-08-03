/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

/*
class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        right=left=null;
    }

    Node(){
        data=0;
        right=left=null;
    }
}
*/

void inorderTraversal(TreeNode *root, vector<int> &inorder){

    if(root == nullptr){
        return ;
    }

    inorderTraversal(root->left,inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);

    return;
}

void preorderTraversal(TreeNode *root, vector<int> &preorder){
    if(root==nullptr) return;

    preorder.push_back(root->data);
    preorderTraversal(root->left,preorder);
    preorderTraversal(root->right, preorder);

    return;
}

void postorderTraversal(TreeNode *root, vector<int> &postorder){
    if(root==nullptr) return;

    postorderTraversal(root->left, postorder);
    postorderTraversal(root->right, postorder);
    postorder.push_back(root->data);

    return;
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    //left root right
    vector<int> inorder;
    inorderTraversal(root, inorder);

    //root left right
    vector<int> preorder;
    preorderTraversal(root, preorder);

    // left right root
    vector<int> postorder;
    postorderTraversal(root, postorder);

    vector<vector<int>> ans;
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);

    return ans;
}