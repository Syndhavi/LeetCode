class Solution {
public:
    void helper(int num,int k,int n,vector<int>& ds,vector<vector<int>>& ans){
        if(num>9 || ds.size()==k){
            if(n==0 && ds.size()==k) ans.push_back(ds);
            return;
        }
        ds.push_back(num);
        helper(num+1,k,n-num,ds,ans);
        ds.pop_back();
        helper(num+1,k,n,ds,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        helper(1,k,n,ds,ans);
        return ans;
    }
};