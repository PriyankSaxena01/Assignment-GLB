class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int x : nums){
            mp[x]++;
        }
        int maxi=INT_MIN;
        for(auto it:mp){
            if(it.second>maxi){
                maxi=it.second;
            }
        }
        int sum=0;
        for(auto it:mp){
            if(maxi==it.second){
                sum+=it.second;
            }
        }
        return sum;
    }
};
