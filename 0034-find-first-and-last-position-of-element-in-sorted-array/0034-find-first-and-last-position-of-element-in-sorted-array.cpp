class Solution {
public:

    int findFirst(vector<int>& nums,int n,int target){
        int l=0,h=n-1;
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]==target){
                ans=mid;
                h=mid-1;
            }
            else if(nums[mid]<target) l=mid+1;
            else h=mid-1;
        }
        return ans;
    }

    int findLast(vector<int>& nums,int n,int target){
        int l=0,h=n-1;
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]==target){
                ans=mid;
                l=mid+1;
            }
            else if(nums[mid]<target) l=mid+1;
            else h=mid-1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int f=findFirst(nums,n,target);
        int l=findLast(nums,n,target);
        return {f,l};
    }
};