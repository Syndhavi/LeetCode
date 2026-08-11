class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.size();
        long long num=0;
        //leading whitespaces
        while(i<n && s[i]==' ') i++;

        //sign
        int sign=1;
        if(i<n && (s[i]=='+'||s[i]=='-')){
            sign=(s[i]=='-')?-1:1;
            i++;
        }

        while(i<n && isdigit(s[i])){
            int dig=s[i]-'0';

            num=num*10 + dig;

            if(sign*num>INT_MAX) return INT_MAX;
            if(sign*num<INT_MIN) return INT_MIN;

            i++;
        }
        return sign*num;
    }
};