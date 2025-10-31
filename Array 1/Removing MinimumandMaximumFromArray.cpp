class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
      if(nums.size()==1)
      return 1;
      int mx=INT_MIN;
      int mini=INT_MAX;
      int id1,id2;
      for(int i=0;i<nums.size();i++)
      {
        if(mx<nums[i])
        {mx=nums[i];
        id1=i;
        }
        if(mini>nums[i])
        {mini=nums[i];
        id2=i;
        }
      }
      if(id1>id2)
      swap(id1,id2);
      int n=nums.size();
      int ans=min(id2+1,min(n-id1,id1+1+n-id2));
      return ans;
    }
};