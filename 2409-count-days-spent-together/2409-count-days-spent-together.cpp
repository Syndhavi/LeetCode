class Solution {
public:
    int daynum(const string& s){
        int dayspermonth[]={31,28,31,30,31,30,31,31,30,31,30,31};
        int mm=stoi(s.substr(0,2));
        int dd=stoi(s.substr(3,2));
        int days=0;
        for(int i=0;i<mm-1;i++){
            days+=dayspermonth[i];
        }
        return days+dd;

    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int as=daynum(arriveAlice);
        int ae=daynum(leaveAlice);
        int bs=daynum(arriveBob);
        int be=daynum(leaveBob);
        int start=max(as,bs);
        int end=min(ae,be);
        return max(0,end-start+1);
    }
};