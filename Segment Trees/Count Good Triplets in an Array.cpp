class Solution {
public:
    using ll = long long;

    void update(int i, int l, int r, int idx, vector<ll>& st){ //update st
        if(l == r){
            st[i] = 1;
            return;
        }

        int mid = l + (r - l)/2;
        if(idx <= mid){
            update(2*i + 1, l, mid, idx, st);
        }

        else{
            update(2*i + 2, mid + 1, r, idx, st);
        }

        st[i] = st[2*i + 1] + st[2*i + 2];
    }

    ll query(int s, int e, int i, int l, int r, vector<ll>& st){ //find common elements on the left of idx in nums2
        if(e < l || s > r){
            return 0;
        }

        else if(s <= l && r <= e){
            return st[i];
        }

        int mid = l + (r - l)/2;
        ll left = query(s, e, 2*i + 1, l, mid, st);
        ll right = query(s, e, 2*i + 2, mid + 1, r, st);

        return left + right;
    } 

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, int> mpp;

        for(int i = 0; i<n; i++){
            mpp[nums2[i]] = i;
        }

        vector<ll> st(4*n);
        update(0, 0, n-1, mpp[nums1[0]], st);

        ll ans = 0;
        for(int i = 1; i<n; i++){
            int idx = mpp[nums1[i]];

            ll leftCommon      = query(0, idx, 0, 0, n-1, st);
            ll leftNotCommon   = i - leftCommon;
            ll rightOfIdxNums2 = n - 1 - idx;
            ll rightCommon = rightOfIdxNums2 - leftNotCommon;

            ans += leftCommon * rightCommon;

            update(0, 0, n-1, idx, st);
        }
        return ans;
    }
};
