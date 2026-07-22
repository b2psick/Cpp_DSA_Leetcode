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
    int ans=0;
    int ok(TreeNode* root){
        if(!root) return 0;
        int a=ok(root->left);
        int b=ok(root->right);
        if(root->val==max({root->val,a,b})) ans++;
        return max({root->val,a,b});
    }
    int countDominantNodes(TreeNode* root) {
        int a=ok(root);
        return ans;
    }
};