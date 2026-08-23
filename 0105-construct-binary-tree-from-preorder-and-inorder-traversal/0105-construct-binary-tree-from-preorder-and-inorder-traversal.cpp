/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int idx = 0;
    TreeNode* fx(vector<int>& preorder, unordered_map<int, int> &in, int low,
                 int high) {
        if (low > high) {
            return nullptr;
        }
        TreeNode* node = new TreeNode(preorder[idx]);
        idx++;
        int id = in[node->val];
        node->left = fx(preorder, in, low, id - 1);
        node->right = fx(preorder, in, id + 1, high);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> in;
        for (int i = 0; i < inorder.size(); i++) {
            in[inorder[i]] = i;
        }
        return fx(preorder, in, 0, preorder.size() - 1);
    }
};