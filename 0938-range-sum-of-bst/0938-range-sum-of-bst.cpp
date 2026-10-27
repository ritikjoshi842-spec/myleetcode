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
int sum = 0;
void fx(TreeNode* &root, int low, int high){
    if(root== nullptr){
        return;
    }
    if(root-> val< low){
        fx(root-> right, low, high);
        return;
    }
    if(root-> val> high){
        fx(root-> left, low, high);
        return;
    }
    sum = sum + root-> val;
    fx(root-> left, low, high);
    fx(root-> right, low, high);
}
    int rangeSumBST(TreeNode* root, int low, int high) {
        fx(root, low, high);
        return sum;
    }
};