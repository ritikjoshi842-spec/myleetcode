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
    void fx(TreeNode* root, int targetSum, int sum, vector<int> &temp, vector<vector<int>> &res){
        if(root== nullptr){
            return;
        }
        sum= sum + root-> val;
        temp.push_back(root-> val);
        if(root-> left== nullptr and root-> right== nullptr){
            if(sum== targetSum){
                res.push_back(temp);
            }
            temp.pop_back();
            return;
        }
        fx(root-> left, targetSum, sum, temp, res);
        fx(root-> right, targetSum, sum, temp, res);
        temp.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> temp;
        fx(root, targetSum, 0, temp, res);
        return res;
    }
};