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
int gx(TreeNode* infected){
    if(infected== nullptr){
        return 0;
    }
    int left = gx(infected-> left);
    int right = gx(infected-> right);
    return 1 + max(left, right);
}
void find(TreeNode* root, TreeNode* &infected, int start){
    if(root== nullptr){
        return;
    }
    if(root-> val == start){
        infected = root;
        return;
    }
    find(root-> left, infected, start);
    find(root-> right, infected, start);
}
int fx(TreeNode* root, int start, int &timer){
    if(root== nullptr){
        return 0;
    }
    if(root-> val == start){
        return -1;
    }
    int left = fx(root-> left, start, timer);
    int right = fx(root-> right, start, timer);
    if(left< 0){
        timer = max(timer, abs(left)+ right);
        return left - 1;
    }
    if(right < 0){
        timer = max(timer, abs(right) + left);
        return right - 1;
    }
    return 1 + max(left, right);
}
    int amountOfTime(TreeNode* root, int start) {
        int timer = 0;
        fx(root, start, timer);
        TreeNode* infected= nullptr;
        find(root, infected, start);
        int h = gx(infected) - 1;
        return max(h, timer);
    }
};