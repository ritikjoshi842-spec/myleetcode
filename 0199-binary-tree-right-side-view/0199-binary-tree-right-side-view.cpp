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
   vector<int> res;
    void fx(TreeNode* root, int lvl){
        if(root== nullptr){
            return;
        }
        if(lvl== res.size()){
            res.push_back(root-> val);
        }
        fx(root-> right, lvl+1);
        fx(root-> left, lvl+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        fx(root, 0);
        return res;
    }
};