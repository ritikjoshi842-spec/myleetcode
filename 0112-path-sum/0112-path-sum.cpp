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
bool res= false;
    void fx(TreeNode *root, int targetSum, int sum){
        if(root== nullptr){
            return;
        }
        sum = sum + root->val;
        if(root-> left== nullptr and root-> right== nullptr){
            if(sum== targetSum){
               res= true;
               return;       
            }
        }
        fx(root-> left, targetSum, sum);
        fx(root-> right, targetSum, sum);
        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        fx(root, targetSum, 0);
        return res;
    }
};