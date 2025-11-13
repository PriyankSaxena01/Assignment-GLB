class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        int total=0;
         unordered_map<int,int> mp;
         int sum=0;
         mp[0]=1;
         for(int i=0;i<arr.size();i++)
         {
             sum+=arr[i];
             if(mp.count(sum))
             {
                 total+=mp[sum];
                 mp[sum]++;
             }
             else
             {
                 mp[sum]=1;
             }
         }
         return total;
         
    }
};
