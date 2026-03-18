class StockSpanner {
public:
    vector<int> prices; //stores the prices
    stack<int> st; // stores indices

    StockSpanner() {}

    int next(int price) {
        int i = prices.size(); //idx of current day is by looking all the days which have come before it
        prices.push_back(price);

        while (!st.empty() && prices[st.top()] <= price) {
            st.pop();
        }
        int span = st.empty() ? (i + 1) : (i - st.top());
        st.push(i);
        return span;        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */