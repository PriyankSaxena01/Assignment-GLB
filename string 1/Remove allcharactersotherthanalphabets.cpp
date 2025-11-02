// User function template for C++

class Solution {
  public:
    string removeSpecialCharacter(string s) {
        // code here
        string ans;
        for(int i=0;i<s.size();i++)
        {
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
            ans.push_back(s[i]);
            else 
            continue;
        }
        if(ans.size()==0)
        return "-1";
        else 
        return ans;
    }
};
