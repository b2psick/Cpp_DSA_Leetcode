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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(root) q.push(root);
        while(!q.empty()){
            int size=q.size();
            int max1=INT_MIN;
            for(int i=0;i<size;i++){
                max1=max(max1,q.front()->val);
                TreeNode* a=q.front();
                q.pop();
                if(a->left) q.push(a->left);
                if(a->right) q.push(a->right);
            }
            ans.push_back(max1);
        }
        return ans;
    }
};