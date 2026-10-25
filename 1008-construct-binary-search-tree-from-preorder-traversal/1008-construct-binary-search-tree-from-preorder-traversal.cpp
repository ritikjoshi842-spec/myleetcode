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
    TreeNode* fx(vector<int>& preorder, int low, int high, int &index){
        if(index== preorder.size()){
            return nullptr;
        }
        if(preorder[index]>= high){
            return nullptr;
        }
        if(preorder[index]<= low){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[index++]);
        root-> left = fx(preorder, low, root-> val, index);
        root-> right = fx(preorder, root-> val, high, index);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return fx(preorder, INT_MIN, INT_MAX, index);
    }
};