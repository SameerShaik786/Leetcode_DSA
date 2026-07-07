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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> ans;
        f(root,targetSum,res,ans);
        return res;
    }
    void f(TreeNode* root,int target,vector<vector<int>> &res,vector<int> &ans){
        if(root == nullptr) return ;
        if(root->left == nullptr && root->right == nullptr && root->val == target){
            ans.push_back(root->val);
            res.push_back(ans);
            ans.pop_back();
            return;
        }
        ans.push_back(root->val);
        f(root->left,target-root->val,res,ans);
        f(root->right,target-root->val,res,ans);
        ans.pop_back();
        return;
    }
};