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
    
    void Inorder(TreeNode* root , vector<int>&ans){
          
          if(root == nullptr) return;

          Inorder(root->left , ans);
          ans.push_back(root->val);
          Inorder(root->right , ans);

    }

    TreeNode* merge(int l , int r , vector<int>&ans){
            if(l > r) return nullptr;

            int mid = l + (r - l)/2;
            TreeNode* root = new TreeNode (ans[mid]);

            root->left = merge(l , mid-1 , ans);
            root->right = merge(mid+1 , r , ans);

            return root;

    }
    TreeNode* balanceBST(TreeNode* root) {

           vector<int>ans;
           Inorder(root , ans);

           return merge(0 , ans.size()-1 , ans);
           
    }
};
