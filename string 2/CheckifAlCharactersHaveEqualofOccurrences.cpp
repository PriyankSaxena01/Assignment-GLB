class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int> mp;
        for(auto i: s)
        {
            mp[i]++;
        }
        if(s.size()==0)
        return true;
        int freq=mp.begin()->second;
        for(auto i : mp)
        {
        if(i.second!=freq)
        return false;
        }
        return true;
    }
};
