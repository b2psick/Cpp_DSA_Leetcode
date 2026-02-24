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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        if(root) q.push(root);
        int count=0;
        while(!q.empty()){
            int size=q.size();
            int prev=INT_MAX;
            for(int i=0;i<size;i++){
                TreeNode* a=q.front();
                q.pop();
                if(count%2==0&&a->val%2==0) return false;
                if(count%2!=0&&a->val%2!=0) return false;
                if(prev==INT_MAX){
                    prev=a->val;
                }else{
                    if(count%2==0){
                        if(a->val<=prev) return false;
                    }else{
                        if(a->val>=prev) return false;
                    }
                    prev=a->val;
                }
                if(a->left) q.push(a->left);
                if(a->right) q.push(a->right);
            }
            count++;
        }
        return true;
    }
};