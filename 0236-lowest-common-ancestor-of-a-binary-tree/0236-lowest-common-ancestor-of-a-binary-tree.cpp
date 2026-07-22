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
    int fx(TreeNode *root, TreeNode *p, TreeNode *q){
        if(root== nullptr){
            return 0;
        }
        int left= fx(root-> left, p, q);
        int right= fx(root-> right, p, q);
        int self= 0;
        if(root== p or root== q){
            self= 1;
        }
        int total = left + right + self;
        if(total== 2 and ans == nullptr){
            ans= root;
        }
        return total;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       fx(root, p, q);
       return ans; 
    }
};