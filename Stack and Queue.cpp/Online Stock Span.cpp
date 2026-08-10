class StockSpanner {
public:
    int ind;
    stack<pair<int, int>> st;
    StockSpanner() {
        ind = -1;
        if(!st.empty()){
            st.pop();
        }
    }
    
    int next(int price) {
        ind += 1;

        while(!st.empty() && st.top().first <= price){
            st.pop();
        }

        int ans = ind - (st.empty() ? -1 : st.top().second);
        st.push({price, ind});
        return ans;
    }
};