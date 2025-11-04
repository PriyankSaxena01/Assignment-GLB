class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
        {   int count=0;
            // int num=nums1[i];
            int eligible=0;
            for(int j=0;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j])
                eligible++;
                else if(nums2[j]>nums1[i] && eligible!=0)
                {
                    count++;
                    ans.push_back(nums2[j]);
                    break;
                }
            }
            if(count==0)
            ans.push_back(-1);
        }
        return ans;
    }
};
