class Solution {
public:

    

    void generateAll(string curr,int open,int close,int n,vector<string>& res){
        if(curr.length()==2*n){
            res.push_back(curr);
            return;
        }
        if(open<n) generateAll(curr+'(',open+1,close,n,res);
        if(close<open) generateAll(curr+')',open,close+1,n,res);
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateAll("",0,0,n,res);
        return res;
    }
};