class Solution {
public:
    bool binarySearch(vector<int>& nums,int l,int r,int& target)
    {
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
            return true;
            if(nums[mid]<target)
            l=mid+1;
            else
            r=mid-1;
        }
        return false;
    }
    int findpivot(vector<int>& nums,int l, int r)
    {
        while(l<r)
        {
            while(l<r && nums[l]==nums[l+1])
            l++;
            
            while(l<r && nums[r]==nums[r-1])
            r--;

            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r])
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        return r;
    }
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int pivot=findpivot(nums,0,nums.size()-1);
        if(binarySearch(nums,0,pivot-1,target))
        return true;

        else

        return binarySearch(nums,pivot,nums.size()-1,target);
    }
};
