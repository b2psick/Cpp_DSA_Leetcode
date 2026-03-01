class Solution {
public:
    int median(vector<int> ok1,int mid){
        for(int i=0;i<ok1.size();i++){
            if(ok1[i]>mid) return i;
        }
        return 0;
    }
    vector<double> sampleStats(vector<int>& nums) {
        vector<double> ans(5);
        vector<int> ok(256);
        int max1=INT_MIN;
        bool flag=false;
        long long sum=0;
        ok[0]=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0&&!flag){
                ans[0]=(double)i;
                flag=true;
            } 
            if(nums[i]!=0) ans[1]=(double)i;
            if(nums[i]>max1){
                ans[4]=(double)i;
                max1=nums[i];
            }
            sum+=(long long)nums[i]*(long long)i;
            if(i!=0) ok[i]=ok[i-1]+nums[i];
        }
        ans[2]=(double)sum/(double)ok[255];
        if(ok[255]%2==0){
            ans[3]=((double)median(ok,ok[255]/2)+(double)median(ok,ok[255]/2-1))/(double)2;
        }else{
            ans[3]=((double)median(ok,ok[255]/2));
        }
        return ans;
    }
};