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
bool fx(TreeNode *root, TreeNode *subRoot){
    if(root== nullptr and subRoot== nullptr){
        return true;
    }
    if(root== nullptr or subRoot== nullptr){
        return false;
    }
    if(root-> val != subRoot-> val){
        return false;
    }
    bool v1= fx(root-> left, subRoot-> left);
    bool v2= fx(root-> right, subRoot-> right);
    if(v1== true and v2== true){
        return true;
    }
    return false;
}
    bool f(TreeNode* root, TreeNode *subRoot){
        if(root== nullptr){
            return false;
        }
        if(root-> val == subRoot-> val and fx(root, subRoot)){
            return true;
        }
        return f(root-> left, subRoot) or f(root-> right, subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return f(root, subRoot);
    }
};