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
        int a=INT_MAX;
        int b=INT_MAX;
        if(root->left){
            if(root->left->val==root->val){
                a=ok(root->left);
            }else ok(root->left);
        }
        if(root->right){
            if(root->right->val==root->val){
                b=ok(root->right);
            }else ok(root->right);
        }
        int max1=0;
        int x=0;
        if(a!=INT_MAX){
            max1=max(max1,a);
            x+=a;
        }
        if(b!=INT_MAX){
            max1=max(max1,b);
            x+=b;
        }
        ans=max(ans,x);
        return 1+max1;
    }
    int longestUnivaluePath(TreeNode* root) {
        ok(root);
        return ans;
    }
};