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
class okk{
public:
    int sum;
    bool is;
    int left;
    int right;
    okk(int left,int right,int sum,bool is){
        this->left=left;
        this->right=right;
        this->sum=sum;
        this->is=is;
    }
};
class Solution {
public:
    int ans=0;
    okk* ok(TreeNode* root){
        okk* left=nullptr;
        okk* right=nullptr;
        if(root->left) left=ok(root->left);
        if(root->right) right=ok(root->right);
        okk* curr=new okk(0,0,root->val,true);
        if(!left&&!right){
            curr->left=root->val;
            curr->right=root->val;
            ans=max(ans,root->val);
            return curr;
        }
        if(!left&&right){
            if(root->val>=right->left||!right->is){
                curr->is=false;
                return curr;
            }
            curr->left=root->val;
            curr->right=right->right;
            curr->sum+=right->sum;
            ans=max(ans,curr->sum);
            cout<<"ok1"<<endl;
            return curr;
        }else if(left&&!right){
            if(root->val<=left->right||!left->is){
                curr->is=false;
                return curr;
            }
            curr->left=left->left;
            curr->right=root->val;
            curr->sum+=left->sum;
            ans=max(ans,curr->sum);
            cout<<"ok2"<<endl;
            return curr;
        }else{
            if(root->val<=left->right||root->val>=right->left||!left->is||!right->is){
                curr->is=false;
                return curr;
            }else{
                curr->left=left->left;
                curr->right=right->right;
                curr->sum+=left->sum;
                curr->sum+=right->sum;
                ans=max(ans,curr->sum);
                cout<<"ok3"<<endl;
                cout<<root->val<<endl;
                return curr;
            }
        }
        return nullptr;
    }
    int maxSumBST(TreeNode* root) {
        okk* a=ok(root);
        return ans;
    }
};