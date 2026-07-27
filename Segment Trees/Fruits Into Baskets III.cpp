class Solution {
public:
    void build(int i, int l, int r, vector<int>& baskets, vector<int>& st){
        if(l == r){
            st[i] = baskets[l];
            return;
        }

        int mid = l + (r - l)/2;

        build(2*i + 1, l, mid, baskets, st);
        build(2*i + 2, mid + 1, r, baskets, st);

        st[i] = max(st[2*i + 1], st[2*i + 2]);
    }

    bool query(int i, int l, int r, int f, vector<int>& st){
        if(st[i] < f){
            return false;
        }

        if(l == r){
            st[i] = -1;
            return true;
        }

        int mid = l + (r - l)/2;
        bool placed = false;

        if(st[2*i + 1] >= f){
            placed = query(2*i + 1, l, mid, f, st);
        } 
        else {
            placed = query(2*i + 2, mid + 1, r, f, st);
        }

        st[i] = max(st[2*i +1], st[2*i + 2]);

        return placed;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> st(4*n, -1);
        int ans = 0;

        build(0, 0, n-1, baskets, st);

        for(auto& f: fruits){
            if(!query(0, 0, n-1, f, st)){
                ans++;
            }
        }
        return ans;
    }
};
