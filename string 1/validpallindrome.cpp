class Solution {
public:
    bool isPalindrome(string s) {
        deque<char> dq;
        for(int i=0;i<s.size();i++)
        {
            char a=s[i];
            if(a>='a' && a<='z' || a>='A' && a<='Z' || a>='0' && a<='9' )
            {   a=tolower(a);
                dq.push_front(a);}
        }
        while(!dq.empty())
        {
            if(dq.front()==dq.back())
            {
                dq.pop_back();
                if(dq.empty())
                break;
                dq.pop_front();
            }
            else
            return false;
            
        }
        return true;
    }
};
