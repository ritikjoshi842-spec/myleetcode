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
int l = 0; int r = 0;
void gx(vector<vector<pair<int, int>>> &res, TreeNode* root, int pos, int lvl){
    if(root== nullptr){
        return;
    }
    res[pos].push_back({lvl, root-> val});
    gx(res, root-> left, pos - 1, lvl+1);
    gx(res, root-> right, pos + 1, lvl+1);
}
void fx(TreeNode* root, int pos){
   if(root== nullptr){
    return;
   }
    l = min(pos, l);
    r = max(pos, r);
    fx(root-> left, pos-1);
    fx(root-> right, pos+1);
}
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        fx(root, 0);
        vector<vector<pair<int, int>>> res(r - l + 1);
        gx(res, root, -1* l, 0);
        for(int i = 0; i< res.size(); i++){
            sort(res[i].begin(), res[i].end());
        }
        vector<vector<int>> ans(r - l + 1);
        for(int i = 0; i< res.size(); i++){
            for(int j = 0; j < res[i].size(); j++){
                ans[i].push_back(res[i][j].second);
            }
        }
        return ans;
    }
};