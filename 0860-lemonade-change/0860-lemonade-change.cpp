class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> b(3,0);
        if(bills[0]!=5) return false;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                b[0]+=1;
            }else if(bills[i]==10){
                if(b[0]==0) return false;
                b[0]-=1;
                b[1]+=1;
            }else{
                if((b[1]==0 && b[0]<3)||b[0]==0) return false;
                if(b[1]>0){
                    b[1]-=1;
                    b[0]-=1;
                }else{
                    b[0]-=3;
                }
                b[2]+=1;
            }
        }
        return true;
    }
};