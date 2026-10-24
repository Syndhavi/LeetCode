class Solution {
private:
   int f(int amount,vector<int>& coins,vector<int>& dp) {
    if(amount==0) return 0;
    if(amount<0) return -1;
    if(dp[amount]!=-2) return dp[amount];
    int minCoins=INT_MAX;
    for(int coin:coins){
        int res=f(amount-coin,coins,dp);
        if(res>=0&&res<minCoins) minCoins=res+1;
    }
    dp[amount]=minCoins==(INT_MAX)?-1:minCoins;
    return dp[amount];
   }

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-2);
        return f(amount,coins,dp);
    }
};