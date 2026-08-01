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
    TreeNode* getbig(stack<TreeNode*> &dsc, TreeNode* root){
       if(dsc.empty()){
        return nullptr;
       }
       TreeNode *temp = dsc.top();
       dsc.pop();
       TreeNode *leftchild= temp-> left;
       while(leftchild!= nullptr){
          dsc.push(leftchild);
          leftchild= leftchild-> right;
       }
       return temp;
    }
    TreeNode* getsmall(stack <TreeNode*> &asc, TreeNode* root){
        if(asc.empty()){
            return nullptr;
        }
        TreeNode *temp2= asc.top();
        asc.pop();
        TreeNode *rightchild= temp2-> right;
        while(rightchild!= nullptr){
            asc.push(rightchild);
            rightchild= rightchild-> left;
        }
        return temp2;
    }
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> asc;
        stack<TreeNode*> dsc;
        if(root== nullptr){
            return false;
        }
        TreeNode *t= root;
        while(t!= nullptr){
            asc.push(t);
            t= t-> left;
        }
        TreeNode *s= root;
        while(s!= nullptr){
            dsc.push(s);
            s= s-> right;
        }
        TreeNode *i= getsmall(asc, root);
        TreeNode *j= getbig(dsc, root);
        while(i and j and i!=j and i-> val <= j-> val){
            if(i-> val + j-> val == k){
                return true;
            }
            else if(i-> val + j-> val> k){
                j= getbig(dsc, root);
            } 
            else{
                i= getsmall(asc, root);
            }
        }
        return false;
    }
};