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
void fx(TreeNode* root){
        if(root== nullptr){
            return;
        }
        if(root-> left!= nullptr){
            if(root-> left -> left== nullptr and root-> left-> right== nullptr){
                sum = sum + root-> left-> val;
            }
        }
        fx(root-> left);
        fx(root-> right);
}
    int sumOfLeftLeaves(TreeNode* root) {
        fx(root);
        return sum;
    }
};