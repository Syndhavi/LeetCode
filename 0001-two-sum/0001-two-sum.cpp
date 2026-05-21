class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
       
        /* for(int i=0;i<n;i++){
            int n1=nums[i];
            for(int j=i+1;j<n;j++){
                int n2=nums[j];
                if(n1+n2==target) return {i,j};
            }
        }
        return {-1,-1}; */

        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int comp=target-nums[i];
            if(mp.find(comp)!=mp.end()){
                return {i,mp[comp]};
            }
            mp[nums[i]]=i;
        }
        return {-1,-1};
    }
};