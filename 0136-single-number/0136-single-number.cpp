class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        /* unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        for(const auto& [element,count] : freq){
            if(count==1) return element;
        }
        return -1; */

        int XOR = 0;
        for(int i=0;i<n;i++) XOR = XOR ^ nums[i];
        return XOR;
    }
};