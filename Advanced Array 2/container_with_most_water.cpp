class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;int j=height.size()-1;
        int ans=0;
        while(i<j)
        {
        int width=j-i;
        int result=width*min(height[i],height[j]);
        ans=max(result,ans);
        if(height[i]<height[j])
        i++;
        else
        j--;
        }
        return ans;
    }
};
