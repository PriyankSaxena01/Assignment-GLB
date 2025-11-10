class Solution {
public:
    int trap(vector<int>& nums) {
        vector<int> maxleft;
        vector<int> maxright;
        int a=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i==0)
            {maxleft.push_back(0);
            continue;
            }
            else if(a<nums[i-1])
            {
                a=nums[i-1];
            }
            maxleft.push_back(a);
        }
        a=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(i==nums.size()-1)
            {maxright.push_back(0);
            continue;
            }
            else if(a<nums[i+1])
            {
                a=nums[i+1];
            }
            maxright.push_back(a);
        }
        reverse(maxright.begin(), maxright.end());
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int temp=min(maxleft[i],maxright[i]);
            if(temp>nums[i])
            {
                ans+=(temp-nums[i]);
            }
        }
        return ans;
    }
};