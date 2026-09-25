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
    void helper(TreeNode* node,vector<int>& preorder){
        if(node==nullptr) return;
        preorder.push_back(node->val);
        helper(node->left,preorder);
        helper(node->right,preorder);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        helper(root,preorder);
        return preorder;
    }
};