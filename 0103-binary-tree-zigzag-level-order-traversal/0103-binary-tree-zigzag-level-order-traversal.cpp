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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        int count = 1;
        queue<TreeNode*> q;
        if(root== nullptr){
          return {};
        }
        q.push(root);
        while(!q.empty()){
            int lvlsize= q.size();
            vector<int> temp;
            while(lvlsize--){
                TreeNode* n= q.front();
                q.pop();
                temp.push_back(n->val);
                if(n-> left!= nullptr){
                   q.push(n-> left); 
                }
                if(n-> right!= nullptr){
                   q.push(n-> right);
                }
            }
            if(count%2== 0){
                reverse(temp.begin(), temp.end());
            }
            res.push_back(temp);
            count++;
        }
        return res;
    }
};