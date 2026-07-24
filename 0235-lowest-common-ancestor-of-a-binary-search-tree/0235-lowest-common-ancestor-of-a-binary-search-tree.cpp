/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode *ans= nullptr;
    void fx(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root== nullptr){
            return;
        }
        if(root-> val== p-> val or root-> val== q-> val){
            ans= root;
            return;
        }
        if(root-> val< p-> val and root-> val< q-> val){
            fx(root-> right, p, q);
        }
        else if(root-> val> q-> val and root-> val > p-> val){
            fx(root-> left, p, q);
        }
        else{
            ans= root;
            return;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fx(root, p, q);
        return ans;
    }
};