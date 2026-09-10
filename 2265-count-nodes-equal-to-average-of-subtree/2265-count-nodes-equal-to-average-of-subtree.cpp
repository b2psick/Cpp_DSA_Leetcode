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
    vector<int> helper(TreeNode* root) {
        if(!root) return {0, 0, 0};
        vector<int> left = helper(root->left);
        vector<int> right = helper(root->right);
        vector<int> curr;
        curr.push_back(left[0] + right[0]);
        curr.push_back(left[1] + right[1]);
        curr.push_back(left[2] + right[2]);
        curr[1] += root->val;
        curr[2]++;
        if(curr[1] / curr[2] == root->val) {
            curr[0]++;
        }
        return curr;
    }

    int averageOfSubtree(TreeNode* root) {
        return (int)helper(root)[0];   
    }
};