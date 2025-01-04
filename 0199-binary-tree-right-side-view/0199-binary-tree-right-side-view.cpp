/**
 * Definition for a binary tree temp.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        if(root == NULL) return res;
        //BFS
        while(!q.empty()) {
            int n = q.size();
            for(int i = n; i > 0; i--) {
                TreeNode * temp = q.front();
                q.pop();
                if(i == n) res.push_back(temp -> val);
                if(temp -> right) q.push(temp -> right);
                if(temp -> left) q.push(temp -> left);
            }
        }
        return res;
    }
};