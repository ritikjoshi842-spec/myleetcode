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
    bool fx(TreeNode* root, TreeNode* subRoot){
        if(root== nullptr and subRoot== nullptr){
            return true;
        }
        if(root== nullptr or subRoot== nullptr){
            return false;
        }
        bool left = fx(root-> left, subRoot-> left);
        bool right = fx(root-> right, subRoot-> right);
        return left && right && root-> val == subRoot-> val;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root== nullptr and subRoot== nullptr){
            return true;
        }
        if(root== nullptr or subRoot== nullptr){
            return false;
        }
        if(root-> val == subRoot-> val and fx(root, subRoot)){
            return true;
        }
        return isSubtree(root-> left, subRoot) or isSubtree(root-> right, subRoot);
    }
};