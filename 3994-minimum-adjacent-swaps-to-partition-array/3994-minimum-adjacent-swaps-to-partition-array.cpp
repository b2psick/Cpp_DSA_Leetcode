class Solution {
public:

    //this is the merge sort sol using inersion count

    // long long merge(vector<int>& arr, int left, int mid, int right, vector<int> aux) {
    //     int i = left;
    //     int j = mid + 1;
    //     long long count = 0;
    //     while(i <= mid || j <= right) {
    //         if(i >= mid + 1) aux.push_back(arr[j++]);
    //         else if(j >= right+1) aux.push_back(arr[i++]);
    //         else if(arr[i] <= arr[j]) aux.push_back(arr[i++]);
    //         else {
    //             aux.push_back(arr[j++]);
    //             count += mid - i + 1;
    //         }
    //     }
    //     for(int i = left; i <= right; i++) {
    //         arr[i] = aux[i - left];
    //     }
    //     return count;
    // }
    // long long mergeSort(vector<int>& arr, int left, int right, vector<int> aux) {
    //     if(left >= right) return 0;
    //     int mid = left + (right - left) / 2;
    //     long long count = 0;
        
    //     count += mergeSort(arr, left, mid, aux)%1000000007;
    //     count += mergeSort(arr, mid + 1, right, aux)%1000000007;
    //     count += merge(arr, left, mid, right, aux)%1000000007;
        
    //     return count%1000000007;
    // }
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]<a) nums[i]=0;
            else if(nums[i]>b) nums[i]=2;
            else nums[i]=1;
        }
        // vector<int> aux;
        // long long ans=mergeSort(nums,0,nums.size()-1,aux)%1000000007;
        long long ans=0;
        int p=0;
        int q=0;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                ans+=q+c;
                ans=ans%1000000007;
            }else if(nums[i]==1){
                ans+=c;
                ans=ans%1000000007;
                q++;
            }else c++;
        }
        return ans;
    }
};