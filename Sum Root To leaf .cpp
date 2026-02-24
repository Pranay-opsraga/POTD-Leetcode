/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isleaf(TreeNode* root){
          return !root->left && !root->right;
    }
    void dfs(TreeNode* root, int curr, int& ans) {

        curr = (curr << 1) | root->val;
        if(isleaf(root)){
             ans += curr;
        }
        if (root->left)
            dfs(root->left, curr, ans);
        if (root->right)
            dfs(root->right, curr, ans);
    }
    int sumRootToLeaf(TreeNode* root) {

        int ans = 0;
        dfs(root, 0, ans);

        return ans;
    }
};
