class Solution {
public:
    
    void merge(vector<int> &arr,int low,int mid,int high)
    {
        int n=arr.size();
        vector<int> temp;
        int i=low;
        int j=mid+1;
        while(i<=mid && j<=high)
        {
            if(arr[i]<=arr[j])
            {
                temp.push_back(arr[i]); i++;
            }
            else{
                temp.push_back(arr[j]); j++;
            }
        }
        while(i<=mid)
        {
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(arr[j]);
            j++;
        }
        for(i=low;i<=high;i++)
        {
            arr[i]=temp[i-low];
        }
    }

    int countPairs(vector<int> &arr, int low, int mid, int high) {
    int cnt = 0;
    int right = mid + 1;
    for (int i = low; i <= mid; i++) {
        while (right <= high && (long long)arr[i] > 2LL * arr[right]) {
            right++;
        }
        cnt += (right - (mid + 1));
    }
    return cnt;
}


    int mergeSort(vector<int> &arr,int low,int high)
    {
        int cnt=0;
        if(low>=high) return cnt;
        int mid=(low+high)/2;
        cnt += mergeSort(arr,low,mid);
        cnt += mergeSort(arr,mid+1,high);
        cnt += countPairs(arr,low,mid,high);
        merge(arr,low,mid,high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergeSort(nums,0,n-1);
    }
};