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
        if(!root) return 1;
        return 2*height(root->left);
    }
    bool ok(TreeNode* root,int left,int right,int nodes,int mid){
        if(nodes==1&&!root) return false;
        else if(nodes==1) return true;
        int mid1=left+(right-left)/2;
        if(mid<=mid1){
            return ok(root->left,left,mid1-1,nodes/2,mid);
        }
        return ok(root->right,mid1+1,right,nodes/2,mid);
    }
    int countNodes(TreeNode* root) {
        int h=height(root)/2;
        int st=1;
        int ed=h;
        int ans=0;
        int st1=1;
        int ed1=h;
        while(st<=ed){
            int mid=st+(ed-st)/2;
            if(ok(root,st1,ed1,h,mid)){
                ans=mid;
                cout<<mid<<endl;
                st=mid+1;
            }else{
                ed=mid-1;
            }
        }
        int a=0;
        h=h/2;
        while(h!=0){
            a+=h;
            h/=2;
        }
        return a+ans;
    }
};