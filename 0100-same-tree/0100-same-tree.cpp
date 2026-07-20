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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p== nullptr and q== nullptr){
            return true;
        }
        if(p== nullptr or q== nullptr){
            return false;
        }
        if(p->val != q->val){
            return false;
        }
        bool v1= isSameTree(p->left, q->left);
        bool v2= isSameTree(p-> right, q-> right);
        if(v1== true and v2== true){
            return true;
        }
        return false;
    }
};