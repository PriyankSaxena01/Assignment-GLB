class StockSpanner {
public:
    stack<pair<int,int>>st ;
    int index;
    StockSpanner() {
        index=-1;
    }
    
    int next(int price) {
        index+=1;
        while(!st.empty() && (st.top().first<=price))
        {
            st.pop();
        }
        int val=index-(st.empty()?-1:st.top().second);
        st.push(make_pair(price,index));
        return val;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */