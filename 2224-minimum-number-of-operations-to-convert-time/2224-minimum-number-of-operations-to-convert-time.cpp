class Solution {
public:
    int mininday(string s){
        int h=stoi(s.substr(0,2));
        int m=stoi(s.substr(3,2));
        int mins=0;
        for(int i=0;i<h;i++){
            mins+=60;
        }
        return mins+m;
    }
    int convertTime(string current, string correct) {
        int c_min=mininday(current);
        int cor=mininday(correct);
        int ans=0;
        if(c_min==cor) return ans;
        while(c_min!=cor){
            int dif=cor-c_min;
            ans++;
            if(dif>=60){
                c_min+=60;
            }else if(dif>=15){
                c_min+=15;
            }else if(dif>=5){
                c_min+=5;
            }else c_min+=1;
        }
        return ans;
    }
};