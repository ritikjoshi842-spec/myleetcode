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
    bool fx(TreeNode *root){
        if(root== nullptr){
            return false;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool checknull = false;
        while(!q.empty()){
           TreeNode *t = q.front();
           q.pop();
           if(t== nullptr){
            checknull = true;
           }
           else{
            if(checknull == true){
                return false;
            }
            else{
                q.push(t-> left);
                q.push(t-> right);
            }
           }
        }
        return true;
    }
    bool isCompleteTree(TreeNode* root) {
        return fx(root);
    }
};