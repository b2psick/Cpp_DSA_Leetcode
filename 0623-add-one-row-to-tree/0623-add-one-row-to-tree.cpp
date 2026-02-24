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
    void ok(TreeNode* root,int val,int depth,int level){
        if(!root) return;
        ok(root->left,val,depth,level+1);
        ok(root->right,val,depth,level+1);
        if(level==depth-1){
            TreeNode* a=new TreeNode(val);
            TreeNode* b=new TreeNode(val);
            a->left=root->left;
            b->right=root->right;
            root->left=a;
            root->right=b;
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* a=new TreeNode(val);
            a->left=root;
            return a;
        }
        ok(root,val,depth,1);
        return root;
    }
};