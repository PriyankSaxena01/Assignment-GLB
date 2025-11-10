class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        // code here
        stack<int> st;
        for(int i=0;i<arr.size();i++)
        {
            string a=arr[i];
            char c=a[0];
            if(a.size()==1 && (c=='+' || c=='-' || c=='*' || c=='/'|| c=='^'))
            {
                int right=st.top();
                st.pop();
                int left=st.top();
                st.pop();
                int ans=0;
                if(c=='+')
                ans=left+right;
                if(c=='-')
                ans=left-right;
                if(c=='*')
                ans=left*right;
                if(c=='/')
                ans=floor((double)left/right);
                if(c=='^')
                ans=pow(left,right);
                
                st.push(ans);
            }
            else
            st.push(stoi(a));
        }
    return st.top();
    }
};
