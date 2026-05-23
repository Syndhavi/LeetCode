class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        /* vector<int> pos;
        vector<int> neg;
        for(int i=0;i<n;i++){
            if(nums[i]>0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }
        for(int i=0;i<n/2;i++){
            nums[2*i]=pos[i];
            nums[(2*i)+1]=neg[i];
        }
        return nums; */

        int posInd=0,negInd=1;
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[posInd]=nums[i];
                posInd +=2;
            }
            else{
                ans[negInd]=nums[i];
                negInd+=2;
            }
        }
        return ans;
    }
};