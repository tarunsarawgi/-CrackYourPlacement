class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       set<vector<int>> s;
       
       int n=nums.size();
       for(int i=0;i<n;i++)
       {
           for(int j=i+1;j<n;j++)
           {
               set<long long> hash;
               for(int k=j+1;k<n;k++)
               {
                   
                       long long sum=nums[i]+nums[j];
                       sum+=nums[k];
                       long long remains=target-sum;
                       if(hash.find(remains)!=hash.end())
                       {
                           vector<int> temp={nums[i],nums[j],nums[k],(int)remains};
                           sort(temp.begin(),temp.end());
                           s.insert(temp);
                       }
                       hash.insert(nums[k]);
                   
               }
           }
       } 
       vector<vector<int>> ans(s.begin(),s.end());
       return ans;
    }
};
