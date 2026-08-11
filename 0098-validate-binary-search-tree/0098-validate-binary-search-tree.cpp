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
    bool check = true;
    void fx(TreeNode *root, TreeNode* & prev){
        if(root== nullptr){
            return;
        }
        fx(root-> left, prev);
        if(prev== nullptr){
            prev= root;
        }
        else if(root-> val <= prev-> val){
            check = false;
            return;
        }
        else{
            prev = root;
        }
        fx(root-> right, prev);
    }
    bool isValidBST(TreeNode* root) {
       TreeNode *prev= nullptr;
       fx(root, prev);
       return check;
    }
};