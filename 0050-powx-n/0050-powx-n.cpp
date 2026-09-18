class Solution {
public:
    double helper(double x,long n){
        if(n==0) return 1.0;
        if(n==1) return x;
        if(n%2==0) return helper(x*x,n/2);
        return x*helper(x,n-1);
    }
    double myPow(double x, int n) {
        long long num=n;
        if(num<0) return (1.0/helper(x,-1*num));
        return helper(x,num);
    }
};