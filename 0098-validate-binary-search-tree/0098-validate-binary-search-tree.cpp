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
bool res = true;
TreeNode* prev = nullptr;
void fx(TreeNode* root){
    if(root==nullptr){
        return;
    }
    fx(root-> left);
    if(prev== nullptr){
        prev= root;
    }
    else{
        if(root-> val<= prev-> val){
            res = false;
            return;
        }
        else{
            prev = root;
        }
    }
    fx(root-> right);
}
    bool isValidBST(TreeNode* root) {
        fx(root);
        return res;


    }
};