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
    int diameter;
public:
    int getWidth(TreeNode* root){
        if(root == nullptr) return 0;
        int lw = getWidth(root -> left);
        int rw = getWidth(root -> right);
        diameter = max(diameter, lw + rw);
        return max(lw, rw) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        getWidth(root);
        return diameter;
    }
};