class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0]!=5) return false;
        int $5d=0,$10d=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                $5d+=1;
            }else if(bills[i]==10){
                if($5d==0) return false;
                $5d-=1;
                $10d+=1;
            }else{
                if(($10d==0 && $5d<3)||$5d==0) return false;
                if($10d>0){
                    $10d-=1;
                    $5d-=1;
                }else{
                    $5d-=3;
                }
            }
        }
        return true;
    }
};