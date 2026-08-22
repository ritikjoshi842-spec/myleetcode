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
TreeNode *g1_first = nullptr;
TreeNode *g2_first = nullptr;
TreeNode *g1_second = nullptr;
TreeNode *g2_second = nullptr;
int wrong   = 0;
    void fun(TreeNode *root){
        if(wrong== 1){
            swap(g1_first-> val, g1_second-> val);
        }
        else{
            swap(g1_first-> val, g2_second-> val);
        }
    }
    void fx(TreeNode *root, TreeNode *&prev){
        if(root== nullptr){
            return;
        }
        fx(root-> left, prev);
        if(prev== nullptr){
            prev= root;
        }
        else if(prev-> val>= root-> val){
            if(wrong== 0){
                g1_first= prev;
                g1_second= root;
                wrong++;
            }
            else{
                g2_first= prev;
                g2_second = root;
                wrong++;
            }
            prev = root;
        }
        else{
            prev = root;
        }
        fx(root-> right, prev);

    }
    void recoverTree(TreeNode* root) {
        TreeNode *prev = nullptr;
        fx(root, prev);
        fun(root);
    }
};