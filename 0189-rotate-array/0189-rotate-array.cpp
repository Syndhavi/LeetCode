class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        /* vector<int> dummy(n);
        for(int i=0;i<n;i++){
            dummy[(i+k)%n]=nums[i];
        }
        for(int i=0;i<n;i++){
            nums[i]=dummy[i];
        } */
        
        /*
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        */

        int count=0;
        for(int start=0;count<n;start++){
            int current=start;
            int prev=nums[start];
            do{
                int next=(current+k)%n;
                int temp=nums[next];
                nums[next]=prev;
                current=next;
                prev=temp;
                count++;
            }while(start!=current);
        }
    }
};