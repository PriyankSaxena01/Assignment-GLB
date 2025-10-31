class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        int n=nums.size();
        // int j=n-1;
        for(int i=0;i<n/2;i++)
        {
        int temp=nums[i];
        nums[i]=nums[n-i-1];
        nums[n-i-1]=temp;
        }
        k=k-1;
        int temp=k;
        int i=0;
        while(i<temp)
        {
            int extra=nums[temp];
            nums[temp]=nums[i];
            nums[i]=extra;
            i++;
            temp--;
        }
        temp=k+1;
        int j=n-1;
        while(j>temp)
        {
            int extra=nums[temp];
            nums[temp]=nums[j];
            nums[j]=extra;
            j--;
            temp++;
        }

    }
};