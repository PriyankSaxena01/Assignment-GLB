// User function template for C++
class Solution {
  public:
  void check1(vector<char>& list, char c)
  {
      for(int i=0;i<list.size();i++)
      {
          if(c==list[i])
          {
              return;
          }
      }
      list.push_back(c);
      return;
  }
    string removeDuplicates(string &s) {
        // code here
        vector<char> list;
        for(int i=0;i<s.size();i++)
        {
            check1(list,s[i]);
        }
        string ans;
        for(int i=0;i<list.size();i++)
        {
            ans+=list[i];
        }
        return ans;
    }
};
