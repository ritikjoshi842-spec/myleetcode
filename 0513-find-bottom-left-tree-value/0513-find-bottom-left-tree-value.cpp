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
int hx(TreeNode* root){
    if(root== nullptr){
        return 0;
    }
    int left = hx(root-> left);
    int right = hx(root-> right);
    return 1 + max(left, right);
}
int fx(TreeNode* root, int num){
    queue<TreeNode*> q;
    q.push(root);
    int i = 0;
    while(!q.empty()){
        i++;
        int lvlsize= q.size();
        if(i== num){
            return q.front()-> val;
        }
        while(lvlsize--){
            TreeNode* temp = q.front();
            q.pop();
            if(temp-> left!= nullptr){
                q.push(temp-> left);
            }
            if(temp-> right!= nullptr){
                q.push(temp-> right);
            }
        }
    }
    return 0;
}
    int findBottomLeftValue(TreeNode* root) {
       int x = hx(root); 
       return fx(root, x);
    }
};