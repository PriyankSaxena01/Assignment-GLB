class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0;i<asteroids.size();i++)
        {
            int val=asteroids[i];
            
            bool change=false;
            while(!st.empty() && st.top()>0 && val<0)
            {
                if(abs(st.top())<abs(val))
                {
                    st.pop();
                    continue;
                }
                else if(abs(st.top())==abs(val))
                {
                    st.pop();
                    change=true;
                    break;
                }
                else{
                    change=true;
                    break;
                }
            }
            if(change==false)
            {
                st.push(val);
            }
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
