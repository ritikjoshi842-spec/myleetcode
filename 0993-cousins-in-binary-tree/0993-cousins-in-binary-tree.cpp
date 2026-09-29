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
bool ans = false;
bool result= false;
void fx(TreeNode* root, int x, int y){
    if(root== nullptr){
      return;
    }
    if(root-> left!= nullptr and root-> right!= nullptr){
    if((root-> left-> val== x) and (root-> right-> val== y)){
        ans = true;
        return;
    }
    if((root-> left-> val == y) and (root-> right-> val== x)){
        ans = true;
        return;
    }
    }
    fx(root-> left, x, y);
    fx(root-> right, x, y);
}
void level(TreeNode* root, int x, int y, int count){
    queue<TreeNode*> q;
    int l1 = -1;
    int l2 = -1;
    q.push(root);
    while(!q.empty()){
        int k = q.size();
        while(k--){
            TreeNode* temp = q.front();
            q.pop();
            if(temp-> val == x){
                l1 = count;
            }
            if(temp-> val == y){
                l2 = count;
            }
            if((l1!= -1) and (l2!= -1) and (l1== l2)){
              result = true;
              break; 
            }
            if(temp-> left!= nullptr){
                q.push(temp-> left);
            }
            if(temp-> right!= nullptr){
                q.push(temp-> right);
            }
        }
        count++;
    }
}
    bool isCousins(TreeNode* root, int x, int y) {
        level(root, x, y, 0);
        if(result== true){
            fx(root, x, y);
            if(ans == false){
                return true;
            }
        }
    return false;
    }
};