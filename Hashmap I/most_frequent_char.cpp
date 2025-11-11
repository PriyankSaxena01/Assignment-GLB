class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        //  code here
        unordered_map<char,int> mp;
        for(auto i: s)
        {
            mp[i]++;
        }
        int freq=0;
        char element='\0';
        for(auto i : mp)
        {
            if(i.second>freq || (i.second == freq && i.first < element))
            {
                freq=i.second;
                element=i.first;
            }
        }
        return element;
    }
};
