class StockSpanner {
public:
    stack<int> st;
    vector<int> v;
    StockSpanner() {
        
    }
    
    int next(int price) {
        v.push_back(price);
        int index = v.size()-1,count = 1;
        while(!st.empty() && v[st.top()] <= price){
            st.pop();
        }
        count = st.empty() ? index+1 : index-st.top();
        st.push(index);
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */