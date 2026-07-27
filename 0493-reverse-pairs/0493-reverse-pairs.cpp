class Solution {
public:
    int rev(vector<int>& arr,int left,int mid,int right) {
        int j = left;
        int count = 0;
        for(int i = mid + 1; i <= right && j <= mid; i++) {
            while(j <= mid && arr[j] <= 2LL * arr[i]) j++;
            count += mid - j + 1;
        }
        return count;
    }
    void merge(vector<int>& arr, int left, int mid, int right, vector<int> aux) {
        int i = left;
        int j = mid + 1;
        while(i <= mid || j <= right) {
            if(i >= mid + 1) aux.push_back(arr[j++]);
            else if(j >= right+1) aux.push_back(arr[i++]);
            else if(arr[i] <= arr[j]) aux.push_back(arr[i++]);
            else {
                aux.push_back(arr[j++]);
            }
        }
        for(int i = left; i <= right; i++) {
            arr[i] = aux[i - left];
        }
    }
    int mergeSort(vector<int>& arr, int left, int right, vector<int> aux) {
        if(left >= right) return 0;
        int mid = left + (right - left) / 2;
        int count = 0;
        
        count += mergeSort(arr, left, mid, aux);
        count += mergeSort(arr, mid + 1, right, aux);
        count += rev(arr, left, mid, right);
        merge(arr, left, mid, right, aux);

        return count;
    }
    int reversePairs(vector<int>& nums) {
        vector<int> aux;
        return mergeSort(nums, 0, nums.size() - 1, aux);
    }
};