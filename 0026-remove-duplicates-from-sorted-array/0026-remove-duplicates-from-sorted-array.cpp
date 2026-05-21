class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n=nums.size();

        /* set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int i=0;
        for(auto it:st){
            nums[i++]=it;
        }
        return st.size(); */

        if(n==0) return 0;
        int i=0;
        for(int j=0;j<n;j++){
            if(nums[j]!=nums[i]){
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};