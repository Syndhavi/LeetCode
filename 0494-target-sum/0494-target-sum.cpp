class Solution {
private:
    int dp(int i,int s,int target,vector<int>& nums){
        if(i==nums.size()){
            if(s==target) return 1;
            else return 0;
        }
        int l=dp(i+1,s+nums[i],target,nums);
        s=s-nums[i];
        int r=dp(i+1,s,target,nums);     
        return l+r;  
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return dp(0,0,target,nums);
    }
};