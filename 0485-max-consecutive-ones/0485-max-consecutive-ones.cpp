class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1) count++;
            if(nums[i]==0 || i==n-1){
                if(count>ans) ans=count;
                count=0;
            }
        }
        return ans;
    }
};