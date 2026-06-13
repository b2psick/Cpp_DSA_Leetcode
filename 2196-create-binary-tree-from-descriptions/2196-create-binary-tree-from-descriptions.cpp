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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        TreeNode* a=nullptr;
        unordered_map<int,TreeNode*> mp;
        unordered_set<int> set;
        for(int i=0;i<d.size();i++){
            TreeNode* child;
            TreeNode* parent;
            if(mp.find(d[i][1])!=mp.end()){
                child=mp[d[i][1]];
            }else{
                child=new TreeNode(d[i][1]);
                mp[d[i][1]]=child;
            }
            if(mp.find(d[i][0])!=mp.end()){
                parent=mp[d[i][0]];
            }else{
                parent=new TreeNode(d[i][0]);
                mp[d[i][0]]=parent;
            }
            set.insert(d[i][1]);
            if(d[i][2]) parent->left=child;
            else parent->right=child;
        }
        for(auto it:set){
            mp.erase(it);
        }
        for(auto it:mp) return it.second;
        return nullptr;
    }
};