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
int find(int target, vector<int>& inorder, int instr, int inend){
    for(int i = instr; i <= inend; i++){
        if(inorder[i]== target){
            return i;
        }
    }
    return -1;
}
TreeNode* fx(int instr, int inend, int idx, vector<int>& preorder, vector<int>& inorder){
    if(inend< instr){
        return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[idx]);
    int pos = find(preorder[idx], inorder, instr, inend);
    root-> left = fx(instr, pos- 1, idx+1, preorder, inorder);
    root-> right = fx(pos + 1, inend, idx + (pos- instr) + 1, preorder, inorder);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int instr = 0;
        int inend = inorder.size()- 1;
        int idx = 0;
        return fx(instr, inend, idx, preorder, inorder);
    }
};