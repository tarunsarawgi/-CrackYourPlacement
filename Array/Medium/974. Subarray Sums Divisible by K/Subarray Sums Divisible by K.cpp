class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        //s=sum
        //r=rem
        //c=count
        int s=0;
        int r=0;
        int c=0;
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            r=s%k;

            if(r<0){
                r=r+k;
            }
            if(r==0){
                c++;
            }
            if(mp.find(r) !=mp.end()){
                c+=mp[r];
                mp[r]++;
            }
            else{
                mp[r]=1;
            }
        }
        return c;
        
    }
};
