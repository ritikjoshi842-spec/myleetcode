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
    bool fx(TreeNode* root1, TreeNode* root2){
        if(root1== nullptr and root2== nullptr){
            return true;
        }
        if(root1== nullptr or root2== nullptr){
            return false;
        }
        if(root1-> val != root2-> val){
            return false;
        }
        if(fx(root1-> left, root2-> right) and fx(root1-> right, root2-> left)
           or fx(root1-> left, root2-> left) and fx(root1-> right, root2-> right)){
            return true;
        }
        return false;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return fx(root1, root2);
    }
};