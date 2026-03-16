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
    void solve(TreeNode* root, vector<int>& arr) {
        if (!root)
            return;

        solve(root->left, arr);
        arr.push_back(root->val);
        solve(root->right, arr);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        solve(root, arr);

        int sum = 0;

        int l = 0;
        int r = arr.size() - 1;

        while (l < r) {
            sum = arr[l] + arr[r];

            if (sum > k)
                r--;
            else if (sum < k)
                l++;
            else
                return true;
        }
        return false;
    }
};
