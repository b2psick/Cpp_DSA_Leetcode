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
    TreeNode* curr = new TreeNode(0);
    void ll(TreeNode* root) {
        if(!root) return;
        curr->right = root;
        curr = root;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        ll(left);
        ll(right);
        root->left = nullptr;
    }
    void flatten(TreeNode* root) {
        ll(root);
    }
};