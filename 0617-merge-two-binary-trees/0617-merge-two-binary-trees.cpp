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
void fx(TreeNode* root1, TreeNode* root2, TreeNode* &root){
    if(!root1 and !root2){
        root= nullptr;
        return;
    }
    if(!root1){
        root = new TreeNode(root2->val);
    }
    else if(!root2){
        root = new TreeNode(root1->val);
    }
    else{
       root = new TreeNode(root1->val + root2->val);
    }
    if(root1 and root2){
        fx(root1->left, root2->left, root->left);
        fx(root1->right, root2->right, root->right);
    }
    else if(root1){
        fx(root1->left, NULL, root->left);
        fx(root1->right, NULL, root->right);
    }
    else{
        fx(NULL, root2->left, root->left);
        fx(NULL, root2->right, root->right);
    }
}
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* root = nullptr;
        fx(root1, root2, root);
        return root;
    }
};