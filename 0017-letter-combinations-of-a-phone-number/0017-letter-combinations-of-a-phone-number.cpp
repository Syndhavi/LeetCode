class Solution {
public:
    void recur(int ind,string digits,string combo[],string curr,vector<string>& ans){
        if(ind==digits.size()){
            ans.push_back(curr);
            return;
        }
        int digit=digits[ind]-'0';
        for(int i=0;i<combo[digit].size();i++){
            recur(ind+1,digits,combo,curr+combo[digit][i],ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        string combo[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string s;
        recur(0,digits,combo,s,ans);
        return ans;
    }
};