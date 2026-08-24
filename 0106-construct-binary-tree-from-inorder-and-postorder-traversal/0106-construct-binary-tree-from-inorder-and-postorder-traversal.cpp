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
    TreeNode *fx(unordered_map<int, int> &in, vector<int> &postorder, int low, int high, int &idx){
        if(low> high){
            return nullptr;
        }
        TreeNode* node = new TreeNode(postorder[idx]);
        idx--;
        int i = in[node-> val];
        node -> right = fx(in, postorder, i + 1, high, idx);
        node -> left = fx(in, postorder, low, i - 1, idx);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> in;
        for(int i = 0; i< inorder.size(); i++){
            in[inorder[i]]= i;
        }
        int idx= postorder.size()- 1;
        return fx(in, postorder, 0, postorder.size()- 1, idx);
    }
};