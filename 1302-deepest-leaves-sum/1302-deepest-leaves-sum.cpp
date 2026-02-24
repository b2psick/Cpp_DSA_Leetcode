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
    int height(TreeNode* root){
        if(!root) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int ans=0;
    void ok(TreeNode* root,int level,int p){
        if(!root) return;
        if(level==p) ans+=root->val;
        ok(root->left,level+1,p);
        ok(root->right,level+1,p);
    }
    int deepestLeavesSum(TreeNode* root) {
        int p=height(root);
        ok(root,1,p);
        return ans;
    }
};