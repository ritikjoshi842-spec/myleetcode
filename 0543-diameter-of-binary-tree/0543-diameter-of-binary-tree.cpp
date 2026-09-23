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
int max_diameter = 0;
int fx(TreeNode* root){
    if(root== nullptr){
        return 0;
    }
    int left = fx(root-> left);
    int right = fx(root-> right);
    int diameter = left + right;
    max_diameter = max(max_diameter, diameter);
    return 1 + max(left, right);
}
    int diameterOfBinaryTree(TreeNode* root) {
        fx(root);
        return max_diameter;
    }
};