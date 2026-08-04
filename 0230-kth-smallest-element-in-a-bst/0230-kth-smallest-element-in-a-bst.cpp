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
    TreeNode *fx(TreeNode* root, int k, stack<TreeNode*> &st){
        if(st.empty()){
           return nullptr;
        }
        TreeNode* t= st.top();
        st.pop();
        TreeNode* rightchild= t-> right;
        while(rightchild!= nullptr){
            st.push(rightchild);
            rightchild= rightchild-> left;
        }
        return t;
    }
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode *x= root;
        while(x!= nullptr){
            st.push(x);
            x= x-> left;
        }
        TreeNode* a;
        for(int i=0; i< k; i++){
           a= fx(root, k, st); 
        }
        return a->val;
    }
};