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
    void ok(TreeNode* root,long long level,long long p){
        if(!root) return;
        p=p*2+root->val;
        if(!root->left&&!root->right){
            ans+=p;
        }
        ok(root->left,level+1,p);
        ok(root->right,level+1,p);
    }
    int sumRootToLeaf(TreeNode* root) {
        ok(root,0,0);
        return ans;
    }
};